/**
 * @file quests.h
 * @brief Ficheiro que contêm a API para a struct QUESTS que contêm uma GHashTable que guarda as perguntas.
 */

#ifndef __QUESTS__
#define __QUESTS__

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "person.h"
#include "question.h"

/**
 * Estrutura da quests.
 * @param questions que representa um apontador para uma GHashTable.
 */
typedef struct quests *QUESTS;

/**
 * Inicia uma nova estrutura quests.
 * @return u que é um apontador para a nova estrutura.
 */
QUESTS init_questions();

/**
 * Adiciona uma QUESTION à estrutura quests.
 * @param u apontador para a estrutura na qual queremos inserir.
 * @param p QUESTION que queremos inserir.
 * @param key long que representa a chave a utilizar na inserção.
 * @return u apontador para a estrutura onde foram inseridos dados.
 */
QUESTS add_question(QUESTS u, QUESTION p, long key);

/**
 * Procura uma QUESTION na estrutura quests.
 * @param u apontador para a estrutura na qual queremos procurar.
 * @param key long que representa a chave a utilizar para procurar na GHashTable.
 * @return u apontador para a estrutura encontrada.
 */
QUESTION get_question(QUESTS u, long key);

/**
 * Remove da memória uma estrutura quests.
 * @param u estrutura que queremos remover da memória.
 * @return Void.
 */
void free_questions(QUESTS u);    

#endif