#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Lovisa Colérus
   2016*/

/*
 * Skriver ut stjärnor i en sinuskurva
 */
int main ()
{   
    int i;
    double x;
    for (x = 0; x <= 6.3; x = x + 0.3){
        for (i = 0; i<(30+15*sin(x)); i = i+1){
            putchar ('*');
        }
        putchar ('\n');
    }
    
        
    
    return 0;
}