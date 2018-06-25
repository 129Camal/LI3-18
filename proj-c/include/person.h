/**
 * @file person.h
 * @brief Ficheiro que contêm a API para a struct person.
 */

#ifndef __PERSON__
#define __PERSON__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

/**
 * Estrutura da person.
 * @param id long que representa o id do utilizador.
 * @param nome char* que representa o nome do utilizador.
 * @param aboutme char* que identifica o AboutMe do utilizador.
 * @param reputacao inteiro que indica a reputação do utilizador.
 * @param nposts inteiro que representa o número de posts efetuados pelo utilizador.
 */
typedef struct person *PERSON;

/**
 * Inicializa a estrutura person alocando memória para a mesma.
 * @param nome char* que representa o nome do utilizador.
 * @param id lon que representa o id do utilizador.
 * @param aboutme char* identifica o AboutMe do utilizador.
 * @param reputacao int que representa a reputação do utilizador.
 * @return r que é um apontador para a estrutura que foi criada.
 */
PERSON create_person(char* nome, long id, char* aboutme, int reputacao, int nposts);

char* get_nome(PERSON u);

int get_reputacao(PERSON u);

int get_nposts(PERSON u);

char* get_aboutmeP(PERSON u); 

/**
 * Incrementa em  um o valor da variável nposts da estrutura person.
 * @param u apontador para estrutura PERSON que representa o utilizador que pretendemos aumentar o nPosts.
 * @return Void.
 */
void set_nposts(PERSON u);

void free_PERSON(PERSON u);

#endif
