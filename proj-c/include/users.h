/**
 * @file users.h
 * @brief Ficheiro que contem a API relativa à implementação de uma estrutura USERS. Que é uma GHashTable que guarda estruturas PERSON.
 */
#ifndef __USERS__
#define __USERS__

#include <glib.h>
#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include "person.h"
/**
 * Estrutura da users.
 * @param users que representa um apontador para uma GHashTable.
 */
typedef struct users *USERS;

/**
 * Inicia uma nova estrutura users.
 * @return u que é um apontador para a nova estrutura criada.
 */
USERS init_users();

/**
 * Adiciona uma PERSON à estrutura users.
 * @param u apontador para a estrutura na qual queremos inserir.
 * @param p PERSON que queremos inserir.
 * @param key long que representa a chave a utilizar na inserção na GHashTable.
 * @return u apontador para a estrutura onde foram inseridos dados.
 */
USERS add_user(USERS u, PERSON p, long key);

/**
 * Procura uma PERSON na estrutura users.
 * @param u apontador para a estrutura na qual queremos procurar.
 * @param key long que representa a chave a utilizar para procurar na GHashTable.
 * @return PERSON apontador para a estrutura encontrada.
 */
PERSON get_user(USERS u, long key);

/**
 * Devolve uma LONG_list dos ids dos utilizadores, ordenada pelos número de posts.
 * @param u apontador para a estrutura na qual queremos procurar informação.
 * @param N inteiro que representa o tamanho da LONG_list a ser devolvida.
 * @return l LONG_list que contêm ids dos utilizadores.
 */
LONG_list top_most_actives(USERS u, int N);

/**
 * Devolve um long* de ids dos utilizadores, ordenada pela sua reputação.
 * @param u apontador para a estrutura na qual queremos procurar informação.
 * @param N inteiro que representa o tamanho do long* a ser devolvido.
 * @return ids long* com os N ids dos utilizadores com mais reputação.
 */
long* top_reputacao(USERS u, int N);

/**
 * Incrementa o número de posts de um utilizador em um.
 * @param u apontador para a estrutura na qual queremos procurar informação.
 * @param key long que representa a chave do utilizador que queremos aumentar o nposts.
 * @return u apontador para a estrutura onde se fez a procura. 
 */
USERS increment_nposts(USERS u, long key);

/**
 * Remove da memória uma estrutura users.
 * @param u apontador para a estrutura que queremos remover da memória.
 * @return Void.
 */
void free_users(USERS u);


#endif