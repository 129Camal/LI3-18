#include "answers.h"

struct answers {
    GHashTable* answers;
};

ANSWERS init_answers(){
    ANSWERS u = malloc(sizeof(struct answers));
    u->answers = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)free_answer);
    return u;
}

ANSWERS add_answer(ANSWERS u, ANSWER p, long key) {
    g_hash_table_insert(u->answers, GSIZE_TO_POINTER(key), p);
    return u;
}

ANSWER get_answer(ANSWERS u, long key) {
    return g_hash_table_lookup(u->answers, GSIZE_TO_POINTER(key));
}

void free_answers(ANSWERS u){
	g_hash_table_remove_all(u->answers);
	g_hash_table_destroy(u->answers);
	free(u);
}
