#include "interface.h"
#include "person.h"
#include "parse.h"
#include "quests.h"
#include "question.h"
#include "answer.h"
#include "tags.h"
#include "time.h"
#include "user.h"
#include "arraydinamico.h"
#include "users.h"
#include "answers.h"
#include "tag.h"
#include "avl.h"

/**
 * Estrutura da TCD_community.
 * @param datesPosts apontador para estrutura que contêm uma GTree.
 * @param users apontador para estrutura que contêm uma GHashTable.
 * @param tags apontador para estrutura que contêm uma GHashTable.
 * @param questions apontador para estrutura que contêm uma GHashTable.
 * @param answers apontador para estrutura que contêm uma GHashTable.
 */
struct TCD_community{
  AVL datesPosts;
	USERS users; 
  TAGS tags; 
  QUESTS questions;
  ANSWERS answers;
};

/**
 * Inicializa a estrutura global.
 * @return Apontador para estrutura inicializada.
 */
TAD_community init(){
  	TAD_community q = malloc(sizeof(struct TCD_community));

    q->datesPosts = init_avl();
  	q->users = init_users();
    q->tags = init_tags();
    q->answers = init_answers();
    q->questions = init_questions();

 	return q;
}

/**
 * Faz load dos dumps.
 * @param u apontador para a estrutura global.
 * @param path char* representa o caminho para a pasta onde se encontram os dumps.
 * @return u apontador para estrutura global.
 */
TAD_community load(TAD_community u, char* path){
	
  char* users = malloc(sizeof(char)*128);
  char* posts = malloc(sizeof(char)*128);
  char* tags = malloc(sizeof(char)*128);

  strcpy(users, path);
  strcpy(posts, path);
  strcpy(tags, path);
  
  strcat(users,"Users.xml");
  strcat(posts,"Posts.xml");
  strcat(tags,"Tags.xml");

  parseUser(u->users, users);
	printf("USERS PARSED!\n");
  
  parsePost(u->users, u->questions, u->answers, u->datesPosts, posts);
  printf("POSTS PARSED!\n");

  parseTags(u->tags, tags);
  printf("TAGS PARSED!\n\n");

  free(users);
  free(posts);
  free(tags);

  return u;
}

/**
 * Query 1.
 * @param com apontador para a estrutura global.
 * @param id long que representa um post.
 * @return r apontador para STR_pair que contém o resultado da query.
 */
STR_pair info_from_post(TAD_community com, long id){
    char* s = NULL;
    char* n = NULL;
    long parentID, idUser;
    QUESTION q;
    PERSON u;
    STR_pair r = create_str_pair(s,n);

    ANSWER a = get_answer(com->answers, id);

    
    if(a==NULL){
  	
      q = get_question(com->questions, id) ;
       
      if(q == NULL){ 
        printf("Post não existe!");
        return r;
      }

      s = get_titulo(q);
      idUser = get_autorQ(q);
       
      u = get_user(com->users, idUser);
      n = get_nome(u);
      
    
    } else{
    
      parentID = get_idpai(a);

      q = get_question(com->questions, parentID);
      s = get_titulo(q);
      
      idUser = get_autorQ(q);
      u = get_user(com->users, idUser);
      n = get_nome(u);
    
    }

    printf("Autor da Pergunta: %s\n", n);
    printf("Titulo: %s\n", s);
    
    return r;
}


/**
 * Query 2.
 * @param com apontador para a estrutura global.
 * @param N inteiro que representa o tamanho máximo do output.
 * @return LONG_list apontador para estrutura llist que contém o resultado da query.
 */
LONG_list top_most_active(TAD_community com, int N){
    
    return top_most_actives(com->users, N);

}


/**
 * Query 3.
 * @param com apontador para a estrutura global.
 * @param begin apontador para estrutura Date.
 * @param end apontador para estrutura Date.
 * @return r apontador para estrutura str_pair que contém o resultado da query.
 */
LONG_pair total_posts(TAD_community com, Date begin, Date end){
    long perguntas = 0;
    long respostas = 0;

    Date atual = begin;
    
    while(compare_data(atual, end) == -1 || compare_data(atual, end) == 0){
        NODE p = get_node(com->datesPosts, atual);
        
        if(p != NULL){
          perguntas += get_sizeQuestions(p);
          respostas += get_sizeAnswers(p);
        }
        atual = incDate(atual);
    }

    LONG_pair r = create_long_pair(perguntas, respostas);
    printf("Perguntas: %ld\n", perguntas);
    printf("Respostas: %ld\n", respostas);
    
    return r;

    
}


/**
 * Query 4.
 * @param com apontador para a estrutura global.
 * @param tag char* que representa a tag a comparar.
 * @param begin apontador para estrutura Date.
 * @param end apontador para estrutura Date.
 * @return r apontador para estrutura llist que contém o resultado da query.
 */
LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end){
    Date atual = end;

    ARRAY_DINAMICO arr = init_array(500);
    
    while(compare_data(begin, atual) == -1 || compare_data(begin, atual) == 0){
          NODE p = get_node(com->datesPosts, atual);

          if(p!=NULL){
            arr = compareTags(p, arr, tag, com->questions);
          }
          atual = decDate(atual);
    }

    LONG_list l = converteArray(arr);
    free_array(arr);
    return l;
} 

/**
 * Query 5.
 * @param com apontador para a estrutura global.
 * @param id long que representa id de um utilizador.
 * @return u apontador para estrutura user que contém o resultado da query.
 */
USER get_user_info(TAD_community com, long id){
      
      USER u = get_user_information(com->datesPosts, com->users, id);
      long* posts = get_10_latest_posts(u);
    
      for(int i = 0; i<10 ; i++){
        printf("%ld\n", posts[i]);

      }
      printf("%s\n", get_bio(u));

      return u;
}
 
/**
 * Query 6.
 * @param com apontador para a estrutura global.
 * @param N int que representa o tamanho máximo do output.
 * @param begin apontador para estrutura Date.
 * @param end apontador para estrutura Date.
 * @return l apontador para estrutura llist que contém o resultado da query.
 */
LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end){
    
    long* ID = calloc(N , sizeof(long));
    int* numvotos = calloc(N , sizeof(int));
    int menor_v = 0;

     while(compare_data(begin, end) == -1 || compare_data(begin, end) == 0){
          NODE p = get_node(com->datesPosts, end);

          if(p!=NULL){
          
          menor_v = get_MostVotes(p, com->answers, N, ID, numvotos, menor_v);
          
          }
      end = decDate(end);
    }

    LONG_list l = create_list(N);
    for(int i=0; i<N; i++){
          printf("%ld\n", ID[i]);
          set_list(l, i, ID[i]);
    }
    free(ID);
    free(numvotos);

    return l;
}


/**
 * Query 7.
 * @param com apontador para a estrutura global.
 * @param N int que representa o tamanho máximo do output.
 * @param begin apontador para estrutura Date.
 * @param end apontador para estrutura Date.
 * @return l apontador para estrutura llist que contém o resultado da query.
 */
LONG_list most_answered_questions(TAD_community com, int N, Date begin, Date end){

    LONG_list l = create_list(N);
    long *ID = calloc(N , sizeof(long));
    int *numrespostas = calloc(N , sizeof(int));
    int menor_v = 0;
  

    while(compare_data(end, begin)==0 || compare_data(end, begin)==1){
      NODE p = get_node(com->datesPosts, end);

      if(p!=NULL){

          menor_v = get_MostAnswers(p, com->questions, N, ID, numrespostas, menor_v);
      
      }
      end = decDate(end);
    }

    for(int i=0; i<N; i++){
          printf("ID %ld\n", ID[i]);
          printf("Nº %d\n", numrespostas[i]);
          set_list(l, i+1, ID[i]);
    }
    free(ID);
    free(numrespostas);

    return l;

}



/**
 * Query 8.
 * @param com apontador para a estrutura global.
 * @param word char* que representa a palavra a comparar.
 * @param N inteiro que representa o tamanho máximo do output.
 * @return LONG_list apontador para estrutura llist que contém o resultado da query.
 */
LONG_list contains_word(TAD_community com, char* word, int N){
    
    return gets_same_word(com->datesPosts, com->questions, word, N);
    
}


/**
 * Query 9.
 * @param com apontador para a estrutura global.
 * @param id1 long que identifica o id de um utilizador.
 * @param id2 long que identifica o id de um utilizador.
 * @param N inteiro que representa o tamanho máximo do output.
 * @return LONG_list apontador para estrutura llist que contém o resultado da query.
 */
LONG_list both_participated(TAD_community com, long id1, long id2, int N){

  return same_questions(com->datesPosts, com->questions, com->answers, id1, id2, N);

}

/**
 * Query 10.
 * @param com apontador para a estrutura global.
 * @param id long que identifica o id de uma pergunta.
 * @return idAnswer long que representa o id da melhor resposta para a pergunta com identificador id.
 */
long better_answer(TAD_community com, long id){
    QUESTION p = get_question(com->questions, id);

    if(p !=NULL){
    
    long idAnswer = get_bestAnswer(p);
    printf("%ld\n", idAnswer);
    return idAnswer;

    } else{

      printf("INVALID QUESTION!");
      return -1;
    
    }
}

/**
 * Query 11.
 * @param com apontador para a estrutura global.
 * @param N inteiro que representa o tamanho máximo do output.
 * @param begin apontador para estrutura Date.
 * @param end apontador para estrutura Date.
 * @return LONG_list apontador para estrutura llist que contém o resultado da query.
 */
LONG_list most_used_best_rep(TAD_community com, int N, Date begin, Date end){
  
  return bestTags(com->tags, com->users, com->questions, com->datesPosts, N, begin, end);

}

/**
 * Liberta a memória ocupada pela estrutura global.
 * @return NULL.
 */
TAD_community clean(TAD_community com){

  free_avl(com->datesPosts);

  free_users(com->users);

  free_tags(com->tags);

  free_questions(com->questions);

  free_answers(com->answers);
  
  free(com);

  return NULL;
}
