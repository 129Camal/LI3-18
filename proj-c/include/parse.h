/**
 * @file parse.h
 * @brief Ficheiro que contêm a API para as funções de parse do input em xml.
 */

#ifndef PARSE_H
#define PARSE_H

#include <libxml/parser.h>
#include <libxml/xmlmemory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "question.h"
#include "answer.h"
#include "person.h"
#include "date.h"
#include "tags.h"
#include "datesposts.h"
#include "users.h"
#include "quests.h"
#include "answers.h"
#include "tag.h"
#include "avl.h"

/**
 * Faz o parse do ficheiro Users.xml e guarda a informação obtida na estrutura.
 * @param users estrutura users na qual queremos guardar a informação obtida através do input Users.xml.
 * @param path char* que representa o caminho para o ficheiro de input.
 * @return int para confirmar se houve problemas na realização da função.
 */
int parseUser(USERS users, char* path);

/**
 * Faz o parse do ficheiro Posts.xml e guarda a informação obtida na estrutura.
 * @param users apontador para estrutura users na qual queremos guardar a informação obtida, através do input Posts.xml, que é relacionada com determinados utilizadores.
 * @param questions apontador para estrutura quests na qual queremos guardar a informação obtida sobre as perguntas.
 * @param answer apontador para estrutura answers na qual queremos guardar a informação obtida sobre as respostas.
 * @param datesPosts apontador para estrutura AVL na qual queremos guardar a informação obtida sobre as respostas, perguntas e utilizadores.
 * @param path char* que representa o caminho para o ficheiro de input.
 * @return int para confirmar se houve problemas na realização da função.
 */
int parsePost(USERS users, QUESTS questions, ANSWERS answer, AVL datesPosts, char* path);

/**
 * Faz o parse do ficheiro Tags.xml e guarda a informação obtida na estrutura.
 * @param tags apontador para estrutura tags na qual queremos guardar a informação obtida sobre as tags.
 * @param path char* que representa o caminho para o ficheiro de input.
 * @return int para confirmar se houve problemas na realização da função.
 */
int parseTags(TAGS tags, char* path);

#endif