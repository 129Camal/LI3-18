/**
 * @file answers.h
 * @brief Ficheiro que contem a API relativa à implementação de uma estrutura TAGS. Que é uma GHashTable que guarda estruturas TAG.
 */

#ifndef __TAGS__
#define __TAGS__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

/**
 * Estrutura da tag.
 * @param id long que identifica o id da tag.
 * @param nome char* que identifica o nome da tag.
 * @param contador inteiro que auxilia na resolução da Query 11.
 */
typedef struct tag *TAG;

/**
 * Inicializa a estrutura tag alocando memória para a mesma.
 * @param id valor long que representa o id da tag.
 * @param nome char* identifica o nome da tag.
 * @return u que é um apontador para a estrutura que foi criada.
 */
TAG create_tag(long id, char* nome);

long get_tagid(TAG u);

char* get_tagnome(TAG u);


int get_contador(TAG u);

/**
 * Incrementa em um o valor da variável contador da estrutura tag.
 * @param u apontador para estrutura tag que pretendemos aumentar o contador.
 * @return Void.
 */
void set_contador(TAG u);

/**
 * Coloca a zero o valor do contador.
 * @param u apontador para estrutura tag que pretendemos colocar a zero o contador.
 * @return Void.
 */
void clean_contador(TAG u);

void free_tag(TAG u);


#endif 