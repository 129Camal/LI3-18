#include <stdlib.h>
#include "date.h"

struct date {
  int day;
  int month;
  int year;
};

Date createDate(int day, int month, int year) {
    Date d = malloc(sizeof(struct date));
    d->day = day;
    d->month = month;
    d->year = year;
    return d;
}

int compare_data(Date a, Date b){
    if(a == NULL) return -1;
    if(b == NULL) return 1;
    
    if (a->year < b->year){return -1;}
    else { if (a->year > b->year) return 1;}

    if (a->year == b->year)
    {
         if(a->month < b->month) return -1;
         if (a->month > b->month) return 1;
         if (a->day < b->day) return -1;
         if(a->day > b->day) return 1;
         
        
    }
    return 0;
}
Date decDate(Date a){
  if(a->day > 1){
    a->day = a->day - 1;
    return a;
  }
  if (a->month == 3){
    if (a->year % 4 == 0){
        if(a->day == 1){ 
          a->month = a->month-1;
          a->day = 29;
          return a;
        }
      } else {
        if(a->day == 1){ 
          a->day = 28;
          a->month = a->month-1;
          return a;
        }
      }
  }
  if(a->month == 1){
    if(a->day == 1){
      a->day = 31;
      a->month = 12;
      a->year = a->year-1;
      return a;
    }
    
  } 

  if(a->month == 2 || a->month == 4 || a->month == 6 || a->month == 8 || a->month == 9 || a->month == 11){
    if(a->day ==1){
         a->day = 31;
         a->month = a->month - 1;
         return a;
    } 
  } else{
    if(a->day == 1){
      a->day = 30;
      a->month = a->month-1;
      return a;
    }
  }
  return a;
}

Date incDate(Date a){
  if (a->month == 2){
    if (a->year % 4 == 0){
        if(a->day < 29){ 
          a->day = a->day+1;
          return a;
        }
        if(a->day == 29){
            a->day = 1;
            a->month = a->month + 1;  
            return a;
        }
      } else {
        if(a->day < 28){ 
          a->day = a->day+1;
          return a;
        }
        if(a->day == 28){
            a->day = 1;
            a->month = a->month + 1;
            return a; 
        }   
      }
  }
  if(a->month == 12){
    if(a->day < 31){ 
        a->day = a->day+1;
        return a;
      }
    if(a->day == 31){
            a->day = 1;
            a->month = 1;
            a->year = a->year + 1;  
            return a;
    }  
  }
  if(a->month == 4 || a->month == 6 || a->month == 9 || a->month == 11){
    if(a->day < 30){
         a->day = a->day+1;
         return a;
    }
    if(a->day == 30){
            a->day = 1;
            a->month = a->month + 1; 
            return a;
    }  
    } else {
        if(a->day < 31){
            a->day = a->day+1;
            return a;
        }
        if(a->day == 31){
            a->day = 1;
            a->month = a->month + 1;
            return a; 
        }  
  }
  return a;
}

int get_day(Date d) {
    return d->day; 
}

int get_month(Date d) {
    return d->month; //change to enum? (Acho que sim. Desta forma já garantimos a limitação necessária)
}

int get_year(Date d) {
    return d->year;
}

void printDate(Date a){
    printf("%d\n", a->day);
    printf("%d\n", a->month);
    printf("%d\n", a->year);
}

void free_date(Date d) {
    free(d);
}

