#include "question.h"

struct question{
     long id;
     char* titulo;
     int nRespostas;
     long autor;
     long bestAnswer;
     float pontuacaoBestA; 
     char** tags;
     int nTags;
};

QUESTION create_question(char* titulo, long id, long autor, int nRespostas){
  
  QUESTION q = malloc(sizeof(struct question)); 
  q->titulo = strdup(titulo);
  q->id = id;
  q->nRespostas = nRespostas;
  q->autor = autor;
  q->bestAnswer = -1;
  q->pontuacaoBestA = 0;
  q->tags = NULL;
  q->nTags = 0;

  return q;
}

char* get_titulo(QUESTION u) {
    char* s = strdup(u->titulo);
    return s;
}

int get_nRespostas(QUESTION u) {
    return u->nRespostas;
}

float get_pontuacaoBestA(QUESTION u) {
    return u->pontuacaoBestA;
}

long get_bestAnswer(QUESTION u){
  return u->bestAnswer;
}

long get_autorQ(QUESTION u) {
    return u->autor;
}

long get_idQ(QUESTION u) {
    return u->id;
}
int get_nTags(QUESTION u) {
    return u->nTags;
}

char* get_tagQ(QUESTION u, int index){
   char* s =u->tags[index];
   return s;
}

void set_nRespostas(QUESTION u){
  u->nRespostas = u->nRespostas+1;

}

void set_tagQ(QUESTION u, int nTags, char** tag){
  int i;
  u->tags = (char**) malloc (nTags * sizeof(char*));
  u->nTags = nTags;

  for(i=0; i<nTags; i++){
    
    u->tags[i] = tag[i]; 
  
  }
}

void set_bestAnswer(QUESTION u, long bestAnswer){
  u->bestAnswer = bestAnswer;
}

void set_pontuacaoBestA(QUESTION u, float pontuacaoBestA){
  u->pontuacaoBestA = pontuacaoBestA;
}

void free_question(QUESTION q) {  
    free(q->tags); 
    free(q);
}

