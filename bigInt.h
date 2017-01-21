
#ifndef BIGINT_H
#define BIGINT_H

/* Lovisa Colérus
   2016*/

struct bigInt{
    int num;
    struct bigInt *tail;
};


typedef struct bigInt bigInt;
bigInt * cons(int num, bigInt * tail);
bigInt * add(bigInt * bigNumber1, bigInt * bigNumber2, int carry);
bigInt * clean(bigInt * bigNumber);
bigInt * invert(bigInt * bigNumber, bigInt * bigNumberTail);
void freeList(bigInt * list);
void printBigInt(bigInt * bigNumber);
void saveToFile(bigInt * bigNumber);
 

#endif /* BIGINT_H */