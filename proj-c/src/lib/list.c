#include <stdlib.h>
#include "list.h"

struct llist {
  int size;
  long* list;
};

LONG_list create_list(int size) {
    if(size <= 0) return NULL;
    LONG_list l = malloc(sizeof(struct llist));
    l->size = size;
    l->list = malloc(sizeof(long) * size);
    return l;
}

long get_list(LONG_list l, int index) {
    return l->list[index]; 
}

void set_list(LONG_list l, int index, long value) {
    l->list[index] = value;
}

/*
void set_ordenacao(LONG_list l, int *v, int N) {
    int tmp;
    long temp;
    for(int i = 1; i<=N; i++){
        for(int j = 2; j<=N; j++){
                
                if(v[i] > v[j]){
                    tmp = v[i];
                    temp = l->list[i];

                    v[i] = v[j];
                    l->list[i] = l->list[j];

                    v[j] = tmp;
                    l->list[j] = temp;
                }
        }
    }
}
*/


void free_list(LONG_list l) {
    if(l) {
        free(l->list);
        free(l);
    }
}

