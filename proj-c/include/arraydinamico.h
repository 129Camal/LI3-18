/**
 * @file arraydinamico.h
 * @brief Ficheiro que contem a API relativa á implementação de um Array Dinâmico.
 */

#ifndef __ARRAY_DINAMICO__
#define __ARRAY_DINAMICO__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "list.h"

/**
 * Estrutura do array_dinamico.
 * @param array long* que guarda longs.
 * @param pos inteiro que corresponde à posição onde vai ser inserido o próximo valor no array.
 * @param capacidade inteiro que representa a capacidade do array dinâmico. 
 */
typedef struct array_dinamico *ARRAY_DINAMICO;

/**
 * Inicia um novo array dinâmico.
 * @param capacidade inteiro que determina a capacidade inicial do array dinâmico.
 * @return conjunto que é um apontador para uma estrutura array_dinamico.
 */
ARRAY_DINAMICO init_array(int capacidade);

/**
 * Adiciona um long passado como argumento na estrutura array_dinamico.
 * @param conjunto apontador para array_dinamico onde será inserido o valor pretendido.
 * @param valor long a colocar na Lista.
 * @return conjunto array_dinamico após a inserção.
 */
ARRAY_DINAMICO array_insert(ARRAY_DINAMICO conjunto, long valor);

/**
 * Remove da memória um dado array_dinamico.
 * @param l Array dinâmico a limpar da memória.
 */
void free_array(ARRAY_DINAMICO l);

/**
 * Converte um array dinâmico para um LONG_list
 * @param arr apontador do array_dinamico a ser convertido.
 * @return l apontador para estrutura llist criada.
 */
LONG_list converteArray(ARRAY_DINAMICO arr);

/**
 * Retorna o campo Pos da estrutura array_dinamico.
 * @param l apontador para array_dinamico.
 * @return int tamanho do array dinâmico.
 */
int getPos(ARRAY_DINAMICO l);

/**
 * Retorna o array que pertence à estrutura array_dinamico.
 * @param l apontador para array_dinamico.
 * @return long* array do array dinâmico.
 */
long* getArray(ARRAY_DINAMICO l);

#endif 