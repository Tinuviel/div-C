#include <stdio.h>
#include <stdlib.h>

/* Lovisa Colérus
   2016*/
   
/* Skriver ut stjärnor */   

//Uppg 2
/*int main ()
{   
    int n = 3;
    int i;
    printf("Skriv in antal stjärnor: ");
    scanf ("%d", &n);
    for (i = 1; i <= n; i = i + 1)
    	putchar ('*');
    putchar ('\n');
    return 0;
}*/


//Uppg 3
int main ()
{   
    int n = 3;
    int i;
    
    while(1){
        printf("Skriv in antal stjärnor: ");
       
        if (scanf ("%d", &n) == EOF) break;
        for (i = 1; i <= n; i = i + 1)
            putchar ('*');
        putchar ('\n');
        
    }
    return 0;
}