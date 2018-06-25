#include "tag.h"

struct tags {
    GHashTable* tags;
};

static int insere_ord(int *nposts, long *ID ,long id, int v, int N);

TAGS init_tags(){
    TAGS u = malloc(sizeof(struct tags));
    u->tags = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify)free_tag);
    return u;
}

TAGS add_tag(TAGS u, TAG p, char* key) {
    char* s = strdup(key);
    g_hash_table_insert(u->tags, s, p);
    return u;
}

TAG get_tag(TAGS u, char* key) {
    char* s = strdup(key);
    return g_hash_table_lookup(u->tags, s);
}


void free_tags(TAGS u){
	g_hash_table_remove_all(u->tags);
	g_hash_table_destroy(u->tags);
	free(u);
 }

LONG_list ordenaTags(TAGS u, int N){
  GHashTableIter iter;
  gpointer key, value;
  long* idtags = calloc(N, sizeof(long));
  int* contags = calloc(N, sizeof(int));
  long idT;
  int cont, i, menor_cont = 0;

  g_hash_table_iter_init(&iter, u->tags);
  while(g_hash_table_iter_next(&iter, &key, &value)){

    TAG t = (TAG)value;
    cont = get_contador(t);
    clean_contador(t);
        
    if(cont >= menor_cont){
      idT = get_tagid(t);

      menor_cont = insere_ord(contags, idtags, idT, cont, N);
    }

  }

  LONG_list l = create_list(N);
  for(i=0; i < N; i++){
          printf("ID TAG: %ld\n", idtags[i]);
          set_list(l, i, idtags[i]);
  }
  free(contags);
  free(idtags);

  return l;
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