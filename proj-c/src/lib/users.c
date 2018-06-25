#include "users.h"

struct users {
    GHashTable* users;
}; 

static int insere_ord(int *nposts, long *ID ,long id, int v, int N);

USERS init_users() {
    USERS u = malloc(sizeof(struct users));
    u->users = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)free_PERSON);
    return u;
}

USERS add_user(USERS u, PERSON p, long key) {
    g_hash_table_insert(u->users, GSIZE_TO_POINTER(key), p);
    return u;
}

PERSON get_user(USERS u, long key) {
    return g_hash_table_lookup(u->users, GSIZE_TO_POINTER(key));
}

USERS increment_nposts(USERS u, long key) {
	PERSON p = g_hash_table_lookup(u->users, GSIZE_TO_POINTER(key));
	
	if(p!=NULL){
		set_nposts(p);
	}
	
	return u;
}

LONG_list top_most_actives(USERS u, int N) { 
	GHashTableIter iter;
    gpointer key, value;
    
    PERSON p;

    LONG_list l = create_list(N);

    long *ID = calloc(N , sizeof(long));
    int *nposts = calloc(N , sizeof(int));
    int menor_v = 0;


    g_hash_table_iter_init(&iter, u->users);
    while(g_hash_table_iter_next(&iter, &key, &value)){
            
        long id = (long)key;
        p = (PERSON)value;
        int numposts = get_nposts(p);
            
        if(numposts){
          if(numposts >= menor_v){
                menor_v = insere_ord(nposts, ID, id, numposts, N);
          }

        }
    }

    for(int i=0; i<N; i++){
          printf("%ld\n", ID[i]);
          set_list(l, i+1, ID[i]);
    }
    free(ID);
    free(nposts);

    return l;
}

long* top_reputacao(USERS u, int N){
	PERSON p;
	int rep, menor_v = 0;
	int* reputacao = calloc(N, sizeof(int));
  	long* ids = calloc(N, sizeof(long));
  	GHashTableIter iter;
  	gpointer key, value;


	g_hash_table_iter_init(&iter, u->users);
  	while(g_hash_table_iter_next(&iter, &key, &value)){
    p = (PERSON)value;
    rep = get_reputacao(p);

    	if(rep >= menor_v){
      		menor_v = insere_ord(reputacao, ids, (long)key, rep, N);
    	}
	}
	return ids;
}

void free_users(USERS u){
	g_hash_table_remove_all(u->users);
	g_hash_table_destroy(u->users);
	free(u);
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
