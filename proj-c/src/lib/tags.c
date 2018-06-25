#include "tags.h"

struct tag {
     long id;
     char* nome;
     int contador;
};

TAG create_tag(long id, char* nome){
	TAG u = malloc(sizeof(struct tag));
	u->id = id;
	u->nome = strdup(nome); 
	u->contador = 0;
	return u;
}

long get_tagid(TAG u){
	return u->id;
}

char* get_tagnome(TAG u){
	return strdup(u->nome);
}

int get_contador(TAG u){
	return u->contador;
}
void clean_contador(TAG u){
	u->contador = 0;
}

void set_contador(TAG u){
	u->contador = u->contador + 1;
}


void free_tag(TAG u) {   
    free(u);
}
