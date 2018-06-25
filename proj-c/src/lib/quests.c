#include "quests.h"

struct quests {
    GHashTable* questions;
};

QUESTS init_questions(){
    QUESTS u = malloc(sizeof(struct quests));
    u->questions = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)free_question);
    return u;
}

QUESTS add_question(QUESTS u, QUESTION p, long key) {
    g_hash_table_insert(u->questions, GSIZE_TO_POINTER(key), p);
    return u;
}

QUESTION get_question(QUESTS u, long key) {
    return g_hash_table_lookup(u->questions, GSIZE_TO_POINTER(key));
}


void free_questions(QUESTS u){
	g_hash_table_remove_all(u->questions);
	g_hash_table_destroy(u->questions);
	free(u);
 }

