#include "list.h"
#include <stdlib.h>

/* Lovisa Colérus
   2016*/
   
/* Skapar en lista */   

IntItem *
cons (int num, IntItem *tail){
    IntItem *cell = malloc (sizeof(IntItem));
    cell->num = num;
    cell->tail = tail;
    return cell;
}

void freeList (IntItem *list){
    while (list!= NULL){
        IntItem *tail = list;
        list = list->tail;
        free(tmp);
    }
}


int
sumList (IntItem *list){
    int sum = 0;
    while(list!= NULL){
        sum += list->num;
        list = list->tail;
    }
}

