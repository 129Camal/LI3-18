/**
 * @file date.h
 * @brief Ficheiro que contêm a API relativa à implementação de uma estrutura Date. 
 */

#ifndef __DATE_H__
#define __DATE_H__


#include <stdio.h>

typedef struct date* Date;

Date createDate(int day, int month, int year);
int get_day(Date d);
int get_month(Date d); // must return a value between 0 and 11 
int get_year(Date d);
void free_date(Date d);

/**
 * Compara duas estruturas date.
 * @param a estrutura date.
 * @param b estrutura date.
 * @return int que representa a veracidade.
 */
int compare_data(Date a, Date b);

/**
 * Incrementa a data em um dia na estrutura date.
 * @param a estrutura date a incrementar.
 * @return a que representa o apontador para a estrutura que foi incrementada.
 */
Date incDate(Date a);

/**
 * Decrementa a data em um dia na estrutura date.
 * @param a estrutura date a decrementar.
 * @return a que representa o apontador para a estrutura que foi decrementada.
 */
Date decDate(Date a);

void printDate(Date a);


#endif
