#include "list.h"
#include <stdlib.h>

/* Lovisa Colérus
   2016*/
   
/* SUmmerar en lista */   

int main(){
    IntItem *list = cons(1, cons(2, cons(3, NULL)));
    printf ("Summan av talen i listan är %d\n", sumList(list));
    freeList(list);
}