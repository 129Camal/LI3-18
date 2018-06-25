/**
 * @file answers.h
 * @brief Ficheiro que contem a API relativa à implementação de uma estrutura answers. Que é uma GHashTable de respostas.
 */

#ifndef __ANSWERS__
#define __ANSWERS__

#include <glib.h>
#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "answer.h"

/**
 * Estrutura da answers.
 * @param answers que representa um apontador para uma GHashTable.
 */
typedef struct answers *ANSWERS;

/**
 * Inicia uma nova estrutura answers.
 * @return u que é um apontador para a nova estrutura.
 */
ANSWERS init_answers();

/**
 * Adiciona uma ANSWER à estrutura ANSWERS.
 * @param u apontador para a estrutura na qual queremos inserir.
 * @param p ANSWER que queremos inserir.
 * @param key long que representa a chave a utilizar na inserção.
 * @return u apontador para a estrutura onde foram inseridos dados.
 */
ANSWERS add_answer(ANSWERS u, ANSWER p, long key);

/**
 * Procura uma ANSWER na estrutura ANSWERS.
 * @param u apontador para estrutura na qual queremos procurar.
 * @param key long que representa a chave a utilizar para procurar na estrutura.
 * @return u apontador para a estrutura onde foram inseridos dados.
 */
ANSWER get_answer(ANSWERS u, long key);

/**
 * Remove da memória uma estrutura answers.
 * @param u estrutura que queremos remover da memória.
 * @return Void.
 */
void free_answers(ANSWERS u);


#endif