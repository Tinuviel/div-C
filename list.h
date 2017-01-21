/*List Library*/

/* Lovisa Colérus
   2016*/

#ifndef LIST_H
#define LIST_H

struct IntItem{
    int num;
    struct IntItem *tail;
 }
 
 typedef struct IntItem IntItem;
 IntItem *cons(int num, IntItem *tail);
 void freeList (IntItem *list);
 sumList(IntItem *list);
 
 
 #endif /* LIST_H */
 
 