/**
 * @file answers.h
 * @brief Ficheiro que contem a API relativa à implementação de uma estrutura TAGS. Que é uma GHashTable que guarda estruturas TAG.
 */

#ifndef __TAG__
#define __TAG__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "tags.h"
#include "list.h"
/**
 * Estrutura da tags.
 * @param tags que representa um apontador para uma GHashTable.
 */
typedef struct tags *TAGS;

/**
 * Inicia uma nova estrutura tags.
 * @return u que é um apontador para a nova estrutura criada.
 */
TAGS init_tags();

/**
 * Adiciona uma TAG à estrutura tags.
 * @param u apontador para a estrutura na qual queremos inserir.
 * @param p TAG que queremos inserir.
 * @param key char* que representa a chave a utilizar na inserção.
 * @return u apontador para a estrutura onde foram inseridos dados.
 */
TAGS add_tag(TAGS u, TAG p, char* key);

/**
 * Procura uma TAG na estrutura tags.
 * @param u apontador para a estrutura na qual queremos procurar.
 * @param key char* que representa a chave a utilizar para procurar na GHashTable.
 * @return TAG apontador para a estrutura encontrada.
 */
TAG get_tag(TAGS u, char* key);

/**
 * Remove da memória uma estrutura tags.
 * @param u apontador para a estrutura que queremos remover da memória.
 * @return Void.
 */
void free_tags(TAGS u);

/**
 * Devolve uma LONG_list com os ids das tags ordenadas pelo contador presente na estrutura apontada por cada TAG presente na GHashTable.
 * @param u apontador para a estrutura que queremos procurar informação.
 * @param N inteiro que indica o tamanho máximo da LONG_list de retorno.
 * @return l, apontador para a lista criada ao executar a função.
 */
LONG_list ordenaTags(TAGS u, int N);


#endif 