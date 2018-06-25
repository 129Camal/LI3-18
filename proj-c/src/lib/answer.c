
#include "answer.h"

struct answer {
     long id;
     long idpai; 
     long autor;
     int Votes;
};
 
ANSWER create_answer(long idpai, long id, long autor, int votes){
  ANSWER r  = malloc(sizeof(struct answer)); 
  r->idpai = idpai;
  r->id = id;
  r->autor = autor;
  r->Votes = votes;
  return r;
}
long get_idpai(ANSWER u){
  return u->idpai;
}


long get_autorA(ANSWER u) {
    return u->autor;
}

long get_idA(ANSWER u) {
    return u->id;
}

int get_Votes(ANSWER u){
    return u->Votes;

}

void free_answer(ANSWER r) {   
    free(r);
}
