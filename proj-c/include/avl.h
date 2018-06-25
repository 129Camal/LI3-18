/**
 * @file avl.h
 * @brief Ficheiro que contêm a API para a struct avl que corresponde a uma GTREE.
 */

#ifndef __AVL__
#define __AVL__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "datesposts.h"
#include "date.h"
#include "user.h"
#include "users.h"
#include "list.h" 
#include "tags.h"
#include "quests.h"
#include "answers.h"

/**
 * Estrutura da AVL.
 * @param avl que representa um apontador para uma GTree.
 */
typedef struct avl *AVL;

/**
 * Inicia uma nova estrutura avl.
 * @return u que é um apontador para a nova estrutura criada.
 */
AVL init_avl();

/**
 * Adiciona uma estrutura NODE à GTree presente na estrutura avl.
 * @param u estrutura na qual queremos inserir.
 * @param p NODE que queremos inserir.
 * @param day estrutura Date que é a chave para a inserção na GTree.
 * @return u apontador para a estrutura avl na qual foi inserido o NODE.
 */
AVL add_node(AVL u, NODE p, Date day);

/**
 * Procura um NODE na GTree presente na estrutura avl.
 * @param u estrutura na qual queremos procurar.
 * @param day estrutura Date que é a chave que queremos procurar na GTree.
 * @return NODE apontador para a estrutura NODE que foi encontrada na GTree.
 */
NODE get_node(AVL u, Date day);

/**
 * Remove da memória uma estrutura avl.
 * @param u estrutura que queremos remover da memória.
 * @return Void.
 */
void free_avl(AVL u);

/**
 * Devolve uma estrutura USER que contêm o AboutMe e os ultimos dez posts do utilizador com um identificador id.
 * @param datesPosts apontador para estrutura AVL na qual está presente a GTree que precisamos de aceder para encontrar informação.
 * @param users apontador para estrutura USERS na qual está presente a GHashTable que precisamos de aceder para encontrar informação.
 * @param id long que representa o identificador do utilizador que queremos obter informação.
 * @return user apontador para a estrutura onde estão presentes os dados encontrados.
 */
USER get_user_information(AVL datesPosts, USERS users, long id);

/**
 * Devolve uma estrutura LONG_list que contêm os ids das perguntas que contêm a word presente no seu título por cronologia inversa.
 * @param datesPosts apontador para estrutura AVL na qual está presente a GTree que precisamos de aceder para encontrar informação.
 * @param questions apontador para estrutura QUESTS na qual está presente a GHashTable que precisamos de aceder para encontrar informação.
 * @param word char* que representa a palavra que queremos ver se existe nos titulos das perguntas.
 * @param N int que representa o tamanho da LONG_list de perguntas que o utilizador do programa quer obter.
 * @return l apontador para a estrutura LONG_list onde estão presentes os dados obtidos.
 */
LONG_list gets_same_word(AVL datesPosts, QUESTS questions, char* word, int N);

/**
 * Devolve uma estrutura LONG_list que contêm os ids das perguntas que dois utilizadores participaram por cronologia inversa.
 * @param datesPosts apontador para estrutura AVL na qual está presente a GTree que precisamos de aceder para encontrar informação.
 * @param questions apontador para estrutura QUESTS na qual está presente a GHashTable que precisamos de aceder para encontrar informação.
 * @param answers apontador para estrutura ANSWERS na qual está presente a GHashTable que precisamos de aceder para encontrar informação.
 * @param id1 long que representa o identificador do utilizador um.
 * @param id2 long que representa o identificador do utilizador dois.
 * @param N int que representa o tamanho da LONG_list de perguntas que o utilizador do programa quer obter.
 * @return list apontador para a estrutura LONG_list onde estão presentes os dados obtidos.
 */
LONG_list same_questions(AVL datesPosts, QUESTS questions, ANSWERS answers, long id1, long id2, int N);

/**
 * Devolve uma estrutura LONG_list que contêm os ids das tags mais utilizadas pelos utilizadores com mais reputação.
 * @param tags apontador para estrutura TAGS na qual está uma GHashTable que precisamos de aceder para encontrar informação.
 * @param users apontador para estrutura USERS na qual está presente uma GHashTable que precisamos de aceder para encontrar informação.
 * @param questions apontador para estrutura QUESTS na qual está presente a GHashTable que precisamos de aceder para encontrar informação.
 * @param datesPosts apontador para estrutura AVL na qual está presente a GTree que precisamos de aceder para encontrar informação.
 * @param begin representa uma estrutura Date que indica a data de inicio de procura.
 * @param end representa uma estrutura Date que indica a a data de fim da procura.
 * @param N int que representa o tamanho da LONG_list de perguntas que o utilizador do programa quer obter.
 * @return list apontador para a estrutura LONG_list onde estão presentes os dados obtidos.
 */
LONG_list bestTags(TAGS tags, USERS users, QUESTS questions, AVL datesPosts, int N, Date begin, Date end);

#endif