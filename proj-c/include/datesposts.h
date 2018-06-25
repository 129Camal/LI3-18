/**
 * @file datesposts.h
 * @brief Ficheiro que contem a API relativa à implementação de uma estrutura NODE. 
 */

#ifndef __DATESPOSTS__
#define __DATESPOSTS__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "quests.h"
#include "answers.h"
#include "arraydinamico.h"
#include "quests.h"
#include "tag.h"

/**
 * Estrutura do datesposts.
 * @param questions que representa um apontador para uma GHashTable.
 * @param answers que representa um apontador para uma GHashTable.
 */
typedef struct datesposts* NODE;

/**
 * Inicia uma nova estrutura datesposts.
 * @return p que é um apontador para a nova estrutura.
 */
NODE create_node();

/**
 * Adiciona uma key e um value à GHashTable identificada pela variável questions presente na estrutura datesposts.
 * @param p apontador para estrutura na qual queremos inserir.
 * @param key long que queremos inserir como chave na GHashTable.
 * @param value long que representa o valor a inserir na GHashTable.
 * @return p apontador para a estrutura onde foram inseridos dados.
 */
NODE set_hashQuestion(NODE p, long key, long value);

/**
 * Adiciona uma key e um value à GHashTable identificada pela variável answers presente na estrutura datesposts.
 * @param p apontador para estrutura na qual queremos inserir.
 * @param key long que queremos inserir como chave na GHashTable.
 * @param value long que representa o valor a inserir na GHashTable.
 * @return p apontador para a estrutura onde foram inseridos dados.
 */
NODE set_hashAnswers(NODE p, long key, long value);

/**
 * Remove da memória uma estrutura datesposts.
 * @param p apontador para a estrutura que queremos remover da memória.
 * @return Void.
 */
void free_NODE(NODE p);

/**
 * Devolve o tamanho da GHashTable apontada pela questions na estrutura datesposts.
 * @param p apontador para a estrutura NODE que contêm a GHashTable.
 * @return s inteiro que representa o tamanho da GHashTable.
 */
int get_sizeQuestions(NODE p);

/**
 * Devolve o tamanho da GHashTable apontada pela answers na estrutura datesposts.
 * @param p apontador para a estrutura NODE que contêm a GHashTable.
 * @return s inteiro que representa o tamanho da GHashTable.
 */
int get_sizeAnswers(NODE p);

/**
 * Verifica as perguntas que contêm uma determinada tag.
 * @param p apontador para estrutura NODE, na qual precisamos de retirar informação.
 * @param arr apontador para array_dinamico no qual inserimos o id da pergunta caso use a tag.
 * @param tag char* que identifica a tag que queremos comparar com as utilizadas pela pergunta.
 * @param questions apontador para estrutura QUESTS que permite procurar informação sobre as perguntas.
 * @return arr apontador para a estrutura onde foram inseridos dados(ARRAY_DINAMICO).
 */
ARRAY_DINAMICO compareTags(NODE p, ARRAY_DINAMICO arr, char* tag, QUESTS questions);

/**
 * Verifica as perguntas que um determinado utilizador realizou.
 * @param p apontador para estrutura NODE, na qual precisamos de retirar informação.
 * @param result long* em que se guardam os ids das perguntas feitas pelo utilizador.
 * @param N inteiro que representa o tamanho do long* result.
 * @param autor long que identifica o id do utilizador a verificar.
 * @return result long* onde foram inseridos os ids das perguntas.
 */
long* compareQuestionUser(NODE p, long* result, int N, long autor);

/**
 * Verifica as respostas que um determinado utilizador realizou.
 * @param p apontador para estrutura NODE,  na qual precisamos de retirar informação.
 * @param result long* em que se guardam os ids das respostas feitas pelo utilizador.
 * @param N inteiro que representa o tamanho do long* result.
 * @param autor long que identifica o id do utilizador a verificar.
 * @return result long* onde foram inseridos os ids das respostas.
 */
long* compareAnswerUser(NODE p, long* result, int N, long autor);

/**
 * Verifica as respostas com mais votos.
 * @param p apontador para estrutura NODE, na qual precisamos de retirar informação.
 * @param answers apontador para a estrutura ANSWERS, onde é preciso ir buscar informação sobre respostas. 
 * @param N inteiro que representa o tamanho de long* ID e int* numvotos.
 * @param ID long* em que se guardam os ids das respostas com mais votos.
 * @param numvotos int* em que se guardam o número de votos que as respostas com mais votos, têm.
 * @param menor_v inteiro que representa o menor valor presente em numvotos, de maneira, a utilizar uma função de ordenação.
 * @return menor_v inteiro que representa o menor valor presente em numvotos no final da função ser executada.
 */
int get_MostVotes(NODE p, ANSWERS answers, int N, long* ID, int* numvotos, int menor_v);

/**
 * Verifica as respostas com mais votos.
 * @param p apontador para estrutura NODE, na qual precisamos de retirar informação.
 * @param questions apontador para a estrutura QUESTS, onde é preciso ir buscar informação sobre perguntas. 
 * @param N inteiro que representa o tamanho de long* ID e int* numrespostas.
 * @param ID long* em que se guardam os ids das perguntas com mais respostas.
 * @param numrespostas int* em que se guardam o número de respostas que as perguntas com mais respostas, têm.
 * @param menor_v inteiro que representa o menor valor presente em numrespostas, de maneira, a utilizar uma função de ordenação.
 * @return menor_v inteiro que representa o menor valor presente em numrespostas no final da função ser executada.
 */
int get_MostAnswers(NODE p, QUESTS questions, int N, long* ID, int* numrespostas, int menor_v);

/**
 * Verifica se determinada palavra existe no título de alguma pergunta. 
 * @param p apontador para estrutura NODE, na qual precisamos de retirar informação.
 * @param result long* em que se guardam os ids das perguntas que contêm a palavra no titulo.
 * @param N inteiro que representa o tamanho de long* result.
 * @param questions apontador para a estrutura QUESTS, onde é preciso ir buscar informação sobre perguntas. 
 * @param word char* que identifica a palavra que queremos verificar se existe no título.
 * @param contador inteiro que representa o número de vezes que foi encontrado um titulo que contêm a palavra.
 * @return contador inteiro que representa o número de vezes que foi encontrado um titulo que contêm a palavra após a conclusão da função.
 */
int get_titles(NODE p, long* result, int N, QUESTS questions, char* word, int contador);

/**
 * Insere nos arrays dinâmicos ids1 e ids2, os ids das perguntas efetuadas, pelos utilizadores identificados com id1 e id2, respetivamente.
 * @param p apontador para estrutura NODE, na qual precisamos de retirar informação.
 * @param ids1 apontador para um array dinâmico. 
 * @param ids2 apontador para um array dinâmico.
 * @param id1 long que representa o id de um utilizador.
 * @param id2 long que representa o id de um utilizador.
 * @return Void.
 */
void setUsersQuestions(NODE p, ARRAY_DINAMICO ids1, ARRAY_DINAMICO ids2, long id1, long id2);

/**
 * Verifica se as respostas dadas pelo utilizador, id1, está relacionada com alguma pergunta em que participou, o utilizador id2. E vice-versa. 
 * @param p apontador para estrutura NODE, na qual precisamos de retirar informação.
 * @param answers apontador para a estrutura ANSWERS, onde é preciso ir buscar informação sobre respostas. 
 * @param ids1 apontador para um array dinâmico.
 * @param ids2 apontador para um array dinâmico.
 * @param id1 long que representa o id de um utilizador.
 * @param id2 long que representa o id de um utilizador.
 * @param result long* onde se guarda o id da pergunta em que ambos participaram.
 * @param N que representa o tamanho máximo de long* result.
 * @param contador inteiro que representa o número de vezes que foi encontrado uma pergunta em que os dois participaram.
 * @return contador inteiro que representa o número de vezes que foi encontrado uma pergunta em que os dois participaram no final da execução da função.
 */
int setUsersAnswers(NODE p, ANSWERS answers, ARRAY_DINAMICO ids1, ARRAY_DINAMICO ids2, long id1, long id2, long* result, int N, int contador);

/**
 * Aumenta o contador presente numa estrutura TAG, quando uma dada pergunta efetuada por um determinado utilizador contêm essa tag.
 * @param p apontador para estrutura NODE, na qual precisamos de retirar informação.
 * @param tags apontador para a estrutura TAGS, onde é preciso ir buscar informação sobre perguntas. 
 * @param questions apontador para a estrutura QUESTS, onde é preciso ir buscar informação sobre respostas. 
 * @param ids long* que contêm N ids de utilizadores.
 * @param N inteiro que representa o tamanho de ids.
 * @return Void.
 */
void countTags(NODE p, TAGS tags, QUESTS questions, long* ids, int N);

#endif