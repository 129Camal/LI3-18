#include "avl.h"

struct avl {
    GTree* avl;
};

typedef struct auxiliar{
  char* word;
  ARRAY_DINAMICO ids1;
  ARRAY_DINAMICO ids2;
  long* result;
  long id1;
  long id2;
  int n;
  int contadorResult; 
  QUESTS perguntas;
  ANSWERS respostas;

} *AUXILIAR;

static gboolean freePosts(gpointer key, gpointer value, GTree* c);

static gboolean tenposts(gpointer keyy, gpointer valuee, AUXILIAR c);

static gboolean compareTitles(gpointer keyy, gpointer valuee, AUXILIAR c);

static gboolean userPosts(gpointer keyy, gpointer valuee, AUXILIAR c);

AVL init_avl(){
    AVL u = malloc(sizeof(struct avl));
    u->avl = g_tree_new_full((GCompareDataFunc)compare_data, NULL, (GDestroyNotify)free_date, (GDestroyNotify)free_NODE);
    return u;
}

AVL add_node(AVL u, NODE p, Date day) {
    
    g_tree_insert(u->avl, day, p);
    return u;

}

NODE get_node(AVL u, Date day) {
    return g_tree_lookup(u->avl, day);
}


void free_avl(AVL u){
	g_tree_foreach(u->avl, (GTraverseFunc)freePosts, u->avl);
  g_tree_destroy(u->avl);
	free(u);
 }

static gboolean freePosts(gpointer key, gpointer value, GTree* c){
    
    g_tree_remove(c, key);
    return FALSE;     

}

USER get_user_information(AVL datesPosts, USERS users, long id){
      
      char* aboutme;
      USER user = NULL;
      
      PERSON p = get_user(users, id);
      
      if(p==NULL){
        printf("INVALID USER ID\n");
        return user;
      }

      AUXILIAR q = malloc(sizeof(struct auxiliar));
      q->n = 10;
      q->id1 = id;
      q->result = calloc(10, sizeof(long));
      q->contadorResult = 0;
      
      
      aboutme = get_aboutmeP(p);
      
      g_tree_foreach(datesPosts->avl, (GTraverseFunc)tenposts, q);

      user = create_user(aboutme, q->result);

      free(q->result);
      free(q);
      
      
      return user;
}

static gboolean tenposts(gpointer keyy, gpointer valuee, AUXILIAR c){
  
    
      c->result = compareQuestionUser((NODE)valuee, c->result, c->n, c->id1);

      c->result = compareAnswerUser((NODE)valuee, c->result, c->n, c->id1);
      
      return FALSE;
}

LONG_list gets_same_word(AVL datesPosts, QUESTS questions, char* word, int N){
    int n = N;

    AUXILIAR c = malloc(sizeof(struct auxiliar));
    c->word = word;
    c->result = calloc(N, sizeof(long));
    c->n = N;
    c->perguntas = questions;
    c->contadorResult = 0;

    g_tree_foreach(datesPosts->avl, (GTraverseFunc)compareTitles, c);
    
    if(c->contadorResult < n) n = c->contadorResult;
    
    LONG_list l = create_list(n);
    for(int i=0; i < n; i++){
      printf("%ld\n", c->result[i]);
      set_list(l, i, c->result[i]);
          
      }
      free(c->result);
      free(c);

      return l;
    
}

static gboolean compareTitles(gpointer keyy, gpointer valuee, AUXILIAR c){
      
      c->contadorResult = get_titles((NODE)valuee, c->result, c->n, c->perguntas, c->word, c->contadorResult);
      
      return FALSE;
}

LONG_list same_questions(AVL datesPosts, QUESTS questions, ANSWERS answers, long id1, long id2, int N){
  int n = N;
  AUXILIAR q = malloc(sizeof(struct auxiliar));
    q->id1 = id1;
    q->id2 = id2;
    q->n = N;
    q->ids2 = init_array(200);
    q->ids1 = init_array(200);
    q->result = calloc(N, sizeof(long));
    q->perguntas = questions;
    q->respostas = answers;
    q->contadorResult = 0;
  
    g_tree_foreach(datesPosts->avl, (GTraverseFunc)userPosts, q);

    if(q->contadorResult < n) n = q->contadorResult;

    LONG_list list = create_list(n);
    for(int i=0; i < n; i++){
          printf("%ld\n", q->result[i]);
          set_list(list, i, q->result[i]);
    }
      free_array(q->ids2);
      free_array(q->ids1);
      free(q->result);
      free(q);

      return list;
}

static gboolean userPosts(gpointer keyy, gpointer valuee, AUXILIAR c){
      
      setUsersQuestions((NODE)valuee, c->ids1, c->ids2, c->id1, c->id2);
      
      c->contadorResult = setUsersAnswers((NODE)valuee, c->respostas, c->ids1, c->ids2, c->id1, c->id2 ,c->result, c->n, c->contadorResult);
      
      return FALSE;
}

LONG_list bestTags(TAGS tags, USERS users, QUESTS questions, AVL datesPosts, int N, Date begin, Date end){
  
  long* ids = top_reputacao(users, N);

  while(compare_data(end, begin)==0 || compare_data(end, begin)==1){

    NODE p = get_node(datesPosts, end);

    if(p!=NULL){

      countTags(p, tags, questions, ids, N);

    }
    end = decDate(end);
  } 
  LONG_list l = ordenaTags(tags, N);
  
  free(ids);

  return l;

}
