#include <stdlib.h>
#include <stdio.h>

#include "complex_list.h"

/* Lovisa Colérus
   2016*/


static ComplexList *
complexListReadFile(char *fileName){
    ComplexList *ls;
    FILE *f = fopen(fileName, "r");
    if(f==NULL){
        fprintf(stderr, "Couldn't do it");
        exit(1);    
    }
    
}

int main (int argc, char *args[]){
    ComplexList *ls1, *ls2, *res;
    ls1 = complexListReadFile (argv[1]);
    ls2 = complexListReadFile (argv[2]);

    res = complexListAdd (ls1, ls2);
    
    complexListPrint (stdout, res);
    return 0;
    
}