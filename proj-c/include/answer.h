/**
 * @file answer.h
 * @brief Ficheiro que contêm a API para a struct answer.
 */

#ifndef __ANSWER__
#define __ANSWER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "date.h"

/**
 * Estrutura da answer.
 * @param id long que identifica o id da resposta.
 * @param idpai long que representa o id da pergunta ao qual esta resposta se dirige.
 * @param autor long que identifica o utilizador que fez a resposta.
 * @param Votes inteiros que representa os votos que a resposta teve.
 */

typedef struct answer *ANSWER;

/**
 * Inicializa a estrutura answer alocando memória para a mesma.
 * @param idpai long que representa o id da pergunta à qual a resposta se refere.
 * @param id lon que representa o id da própria resposta.
 * @param autor long que identifica o id do utilizador que postou a resposta.
 * @param votes int que representa o número de votos recebidos pela resposta.
 * @return r que é um apontador para a estrutura que foi criada.
 */
ANSWER create_answer(long idpai, long id, long autor, int votes);

long get_idA(ANSWER u);

long get_autorA(ANSWER u);

long get_idpai(ANSWER u);

int get_Votes(ANSWER u);

/**
 * Remove da memória uma estrutura answer.
 * @param u apontador para a estrutura que queremos remover da memória.
 * @return Void.
 */
void free_answer(ANSWER r);


#endif