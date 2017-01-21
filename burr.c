#include <stdlib.h>
#include <stdio.h>

/* Lovisa Colérus
   2016*/

int main(){
    printf("Skriv in ditt burrnr (Siffra mellan 1-9): ");
    int burr;
    int i;
    char str[3];
    char str1[2];
    scanf("%d", &burr);
    
    /* sprintf gör om talet till en string*/
    sprintf(str1, "%d", burr);
    
    /* loopar över 1-99 */
    for(i = 1; i<100; i = i+1){
        sprintf(str, "%d", i);
        
        //kollar ifall någon av siffrorna i talet är burrsiffran eller om det är delbart med burrsiffran
        if(i%burr == 0){
            printf("burr ");
        }else{
            if(str[0] == str1[0]){
                printf("burr ");
            }else if(str[1] == str1[0]){
                printf("burr ");
            }else{
                printf("%d ", i);
            }
            
        }
    }
    
    
    
    return 0;
}