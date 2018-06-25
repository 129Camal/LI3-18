/**
 * @file question.h
 * @brief Ficheiro que contêm a API para a struct question.
 */

#ifndef __QUESTION__
#define __QUESTION__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"
#include "tags.h"

/**
 * Estrutura das perguntas - question.
 * @param id long que representa o id da pergunta.
 * @param titulo char* que representa o titulo de uma pergunta.
 * @param nRespostas int que representa o número de respostas que a pergunta tem.
 * @param autor long identifica o id do autor da pergunta.
 * @param bestAnswer long que identifica a melhor resposta à pergunta.
 * @param pontuacaoBestA float que identifica a pontuação da melhor resposta da pergunta.
 * @param tags char** que guarda as tags que cada pergunta contêm.
 * @param nTags inteiro que representa o número de tags que a pergunta tem.
 */
typedef struct question *QUESTION;

/**
 * Inicializa a estrutura question alocando memória para a mesma.
 * @param titulo char* que representa o titulo de uma pergunta.
 * @param id lon que representa o id da pergunta.
 * @param autor long identifica o id do autor da pergunta.
 * @param nRespostas int que representa o número de respostas que a pergunta tem.
 * @return q que é um apontador para a estrutura question que foi criada.
 */
QUESTION create_question(char* titulo, long id, long autor, int nRespostas);

void free_question(QUESTION q);

char* get_titulo(QUESTION u);

int get_nRespostas(QUESTION u);

long get_autorQ(QUESTION u);

long get_idQ(QUESTION u);

int get_nTags(QUESTION u);

char* get_tagQ(QUESTION u, int index);

void set_nRespostas(QUESTION u);

void set_tagQ(QUESTION u, int nTags, char** tag);

void set_bestAnswer(QUESTION u, long bestAnswer);

void set_pontuacaoBestA(QUESTION u, float pontuacaoBestA);

long get_bestAnswer(QUESTION u);

float get_pontuacaoBestA(QUESTION u);

#endif