#include "person.h"

struct person {
     long id;
     char* nome;
     char* aboutme;
     int reputacao;
     int nposts;
};


PERSON create_person(char* nome, long id, char* aboutme, int reputacao, int nposts){
  PERSON u = malloc(sizeof(struct person)); 
  
  u->nome = strdup(nome);
  u->id = id;
  u->aboutme = strdup(aboutme);
  u->reputacao = reputacao;
  u->nposts = 0;
  return u;
}

char* get_nome(PERSON u) {
    return strdup(u->nome);
}

int get_reputacao(PERSON u) {
    return u->reputacao;
}

int get_nposts(PERSON u) {
    return u->nposts;
}

char* get_aboutmeP(PERSON u) {
    char* s = strdup(u->aboutme);
    return s;
}

void set_nposts(PERSON u) {
    u->nposts = u->nposts + 1;
}

void free_PERSON(PERSON u) {  
    free(u);
}
