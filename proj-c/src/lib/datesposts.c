#include "datesposts.h"

struct datesposts{
	GHashTable* questions;
	GHashTable* answers;
};

static void insert(long *ID , long iden, int N);

static int insere_ord(int *nposts, long *ID ,long id, int v, int N);

NODE create_node(){
	NODE p = malloc(sizeof(struct datesposts));
	p->questions = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, NULL);
	p->answers = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, NULL);
	return p;
}

NODE set_hashQuestion(NODE p, long key, long value){
	g_hash_table_insert(p->questions, GSIZE_TO_POINTER(key), GSIZE_TO_POINTER(value));
	return p;
}

NODE set_hashAnswers(NODE p, long key, long value){
	g_hash_table_insert(p->answers, GSIZE_TO_POINTER(key), GSIZE_TO_POINTER(value));
	return p;
}

int get_sizeQuestions(NODE p){

	int s = g_hash_table_size(p->questions);
	return s; 

}

int get_sizeAnswers(NODE p){

	int s = g_hash_table_size(p->answers);
	return s; 

}

ARRAY_DINAMICO compareTags(NODE p, ARRAY_DINAMICO arr, char* tag, QUESTS questions){
	 GHashTableIter iter;
    gpointer key, value;
    QUESTION q;
    
    int nTags, j;
    char* s;

	g_hash_table_iter_init(&iter, p->questions);
    while(g_hash_table_iter_next(&iter,  &key, &value)){
        
        q = get_question(questions, (long)key);   

        nTags = get_nTags(q);
                    
        for(j = 0; j < nTags; j++){
               s = get_tagQ(q, j);

                if(strcmp(s, tag) == 0){
                    array_insert(arr, (long)key);
                }        
         }
    }
    return arr;
}

long* compareQuestionUser(NODE p, long* result, int N, long autor){
 	
 	GHashTableIter iter;
  gpointer key, value;
  long id, idAutor;

 	g_hash_table_iter_init(&iter, p->questions);
    while(g_hash_table_iter_next(&iter, &key, &value)){
        
      idAutor = (long)value;
      id = (long)key;

      if(idAutor == autor){
            insert(result, id, N);
      
      }
  	}
    
  	return result;

}

long* compareAnswerUser(NODE p, long* result, int N, long autor){
 	
 	GHashTableIter iter;
  gpointer key, value;
  long id, idAutor;

 	g_hash_table_iter_init(&iter, p->answers);
    while(g_hash_table_iter_next(&iter, &key, &value)){
        
      idAutor = (long)value;
      id = (long)key;

      if(idAutor == autor){
            insert(result, id, N);
      
      }
  	}
  	return result;

}

int get_MostVotes(NODE p, ANSWERS answers, int N, long* ID, int* numvotos, int menor_v){
    GHashTableIter iter;
    gpointer key, value;
    ANSWER a;
    long id;

    g_hash_table_iter_init(&iter, p->answers);
    while(g_hash_table_iter_next(&iter, &key, &value)){

      id = (long)key;

      a = get_answer(answers, id);

      if(a!=NULL){
          int nvotos = get_Votes(a); 
                   
                if(nvotos >= menor_v){
                    menor_v = insere_ord(numvotos, ID, id, nvotos, N);
                    
                }
      }
    }

    return menor_v;
}

void free_NODE(NODE p){

	g_hash_table_remove_all(p->questions);
	g_hash_table_destroy(p->questions);
	g_hash_table_remove_all(p->answers);
	g_hash_table_destroy(p->answers);

  	free(p);
} 

static void insert(long *ID , long iden, int N){
      int i;
      long tmp;

      for (i=N-1; i>0; i--){
            
            tmp = ID[i-1];
            ID[i] = tmp;
      }
      ID[i] = iden;
}

static int insere_ord(int *nposts, long *ID ,long id, int v, int N){
      int i, j;

      for (i=0; i<N; i++){
            if (v >= nposts[i]){
                  if (v == nposts[i] && id > ID[i]);
                  else {
                        for ( j=N-1 ; j>i ; j--){
                              nposts[j] = nposts[j-1];
                              ID[j] = ID[j-1];
                        }
                        nposts[i] = v;
                        ID[i] = id;
                        break;
                  }
            }
      }
      return nposts[N-1];
}
int get_MostAnswers(NODE p, QUESTS questions, int N, long* ID, int* numrespostas, int menor_v){
      GHashTableIter iter;
      gpointer key, value;
      QUESTION q;
      long id;
      int nres;

      g_hash_table_iter_init(&iter, p->questions);
      while(g_hash_table_iter_next(&iter, &key, &value)){
   
          id = (long)key;
          q = get_question(questions, id);

          if(q!=NULL){
        
            nres = get_nRespostas(q);   
            if(nres >= menor_v){
                  menor_v = insere_ord(numrespostas, ID, id, nres, N);

            }
          
          }
      }
      return menor_v;
}


int get_titles(NODE p, long* result, int N, QUESTS questions, char* word, int contador){
      GHashTableIter iter;
      gpointer key, value;
      QUESTION q;
      char* title;
      long id;

      g_hash_table_iter_init(&iter, p->questions);
      while(g_hash_table_iter_next(&iter, &key, &value)){
        
        q = get_question(questions, (long)key);
        
        if(q!=NULL){
          title =  get_titulo(q);

          if(title != NULL){

            if(strstr(title, word)!=NULL){
          
              id = get_idQ(q);
              insert(result, id, N);
              contador++;
            }
          }
        }
      }
      return contador;
}

void setUsersQuestions(NODE p, ARRAY_DINAMICO ids1, ARRAY_DINAMICO ids2, long id1, long id2){
  GHashTableIter iter;
  gpointer key, value;
  long idAutor, id;

  g_hash_table_iter_init(&iter, p->questions);
  while(g_hash_table_iter_next(&iter, &key, &value)){
        
    idAutor = (long)value;
    id = (long)key;

    if(idAutor == id1){
        array_insert(ids1, id);
              
    }
        
    if(idAutor == id2){
      array_insert(ids2, id);
    }

  }
}

int setUsersAnswers(NODE p, ANSWERS answers, ARRAY_DINAMICO ids1, ARRAY_DINAMICO ids2, long id1, long id2, long* result, int N, int contador){
      GHashTableIter iter;
      gpointer chave, valor;
      ANSWER a;
      long pai, idAutor, id;
      int pos2, pos1, i;
      long* ids21, *ids22;

      g_hash_table_iter_init(&iter, p->answers);
      while(g_hash_table_iter_next(&iter, &chave, &valor)){

          idAutor = (long)valor;
          id = (long)chave;

          
          if(idAutor == id1){
            
            a = get_answer(answers, id); 

            pai = get_idpai(a);

            pos2 = getPos(ids2);
            ids22 = getArray(ids2);

            for(i = 0; i < pos2; i++){
              
              if(ids22[i] == pai){

                insert(result, pai, N);
                contador++;
                break;
              }
            
            } 
            array_insert(ids1, pai);
            
          
          }

          if(idAutor == id2){
            
            a = get_answer(answers, id);
            
            pai = get_idpai(a);

            pos1 = getPos(ids1);
            ids21 = getArray(ids1);

            for(i = 0; i < pos1; i++){
              
              if(ids21[i] == pai){
                insert(result, pai, N);
                contador++;
                break;
              } 
              
            }
            array_insert(ids2, pai); 
          
          }
          
      }
      return contador;
}

void countTags(NODE p, TAGS tags, QUESTS questions, long* ids, int N){
  GHashTableIter iter;
  gpointer key, value;
  long autor;
  int nTags, i, j;
  char* tagg;
  TAG t; 

  g_hash_table_iter_init(&iter, p->questions);
      while(g_hash_table_iter_next(&iter, &key, &value)){
        
        autor = (long)value;
        for(i = 0; i < N; i++){
          
          if(ids[i] == autor){
            QUESTION q = get_question(questions, (long)key);

            nTags = get_nTags(q);
            
            for(j = 0; j < nTags; j++){

              tagg = get_tagQ(q, j);

              t = get_tag(tags, tagg);
              if(t!=NULL){
                set_contador(t);
              }
            }
          }
        }
      }
}
