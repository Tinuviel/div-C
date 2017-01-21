#include "bigInt.h"
#include <stdio.h>
#include <stdlib.h>

/* Lovisa Colérus
   2016*/

/* Konstruerar en bigInt */
bigInt *cons(int num, bigInt * tail){
    bigInt *cell;
    cell = malloc(sizeof (bigInt));
    cell->num = num;
    cell->tail = tail;
    return cell;
}

/* Friar minnet */
void freeList(bigInt * list){
    bigInt * tmp;
    while(list != NULL){
        tmp = list;
        list = list->tail;
        free(tmp);
    }
}

/* Skapar en bigInt från en sträng */
bigInt * createBigInt(char * string){
    bigInt * bigNumber;
    bigNumber = NULL;
    
    char * item = string;
    while(*item != 0){
        int num = (*item-'0');
        if(0<=num && num<=9){
            bigNumber = cons(num, bigNumber);
            ++item;
        }else{
            printf("Fel inmatning\n");
            return NULL;
        }
    }
    return bigNumber;
}

void saveToFile(bigInt * bigNumber){
    FILE *f;
    f = fopen("resultat.txt", "w");
    if(f == NULL){
        printf("error opening file\n");
        exit(1);
    }
    fprintf(f, "talet är: ");
    while(1){
        int num = bigNumber->num;
        
        fprintf(f, "%d", num);
        bigNumber = bigNumber->tail;
        if(bigNumber == NULL){
            break;
            
        }
    }
    fclose(f);
    
    
    
}

/* Skriver ut en bigInt som en sträng */
void printBigInt(bigInt * bigNumber){
    if(bigNumber->tail != NULL){
        printBigInt(bigNumber->tail);      
    }
    printf("%d", (bigNumber->num));   
}

/* Adderar två bigInt rekursivt
 * Ifall båda listorna är tomma returnerar den NULL
 * Avslutar programmet vid ctrl-d
 */
bigInt * add(bigInt * bigNumber1, bigInt * bigNumber2, int carry){
    int newNum1, newNum2, sum;
    bigInt * bigSum = NULL;
    
        /* Körs när båda listorna har innehåll
         * adderar num i listorna stegvis och skickar med en carry 
         * ifall summan av två platser överstiger 9
         */
    if((bigNumber1 != NULL) && (bigNumber2 != NULL)){
        newNum1 = bigNumber1->num;
        newNum2 = bigNumber2->num;
        sum = newNum1 + newNum2 + carry;
        
        if(sum >= 10){
            sum = sum-10;
            carry = 1;
        }else{
            carry = 0;
        }
        bigSum = cons(sum, bigSum);      
    }
    
    /* ifall bigNumber2 inte har några fler värden */
    if((bigNumber1 != NULL)&& (bigNumber2 == NULL)){
        sum = bigNumber1->num;
        if(carry != 0){
            sum = sum+carry;
            if(sum>=10){
                sum = sum-10;
                carry = 1;
            }else{
                carry = 0;
            }
        }
        bigSum = cons(sum, bigSum);
        return cons(sum, add(bigNumber1->tail, NULL, carry));
    }
    
    
    /* ifall bigNumber1 inte har några fler värden */    
    if((bigNumber2 !=NULL)&&(bigNumber1==NULL)){
        sum = bigNumber2->num;
        if(carry != 0){
            sum = sum+carry;
            if(sum>=10){
                sum = sum-10;
                carry = 1;
            }else{
                carry = 0;
            }
        }
        bigSum = cons(sum, bigSum);
        
        return cons(sum, add(NULL, bigNumber2->tail, carry));
    }
    
    /* ifall båda listorna är tomma av slutar vi den rekursiva funktionen */
    if((bigNumber1==NULL) && (bigNumber2 == NULL)){
        return bigSum;
    }
    
    return cons(sum, add(bigNumber1->tail, bigNumber2->tail, carry));
}


/* tar bort nollor i början av talen */
bigInt * clean(bigInt * bigNumber){
    while(1){
        if(bigNumber->num == 0){
            bigNumber = bigNumber->tail;
        }else{
            break;
        }
    }
    return bigNumber;
}
/* Inverterar siffran */
bigInt * invert(bigInt * parent, bigInt * current){
    if(current == NULL){
        return parent;
    } 
    bigInt * restOfList = current->tail;
    current->tail = parent;
    return invert(current, restOfList);

}

/* Adderar två bigInt som användaren har matat in som strängar
 * Avslutar vid ctrl-d
 */
int main(){
    char bigNumberString1[501];
    char bigNumberString2[501];
    bigInt * sum;
    printf("\nDet här programmet adderar stora positiva heltal med max 500 siffror");
    
    while(1){
        printf("\nAnge ett tal eller ctrl-d för att avsluta: ");
        if(scanf("%s", bigNumberString1)<0){
            break;
        }else{
            bigInt * bigNumber1 = createBigInt(bigNumberString1);
            if(bigNumber1 == NULL) continue;
            printf("\nAnge ett till tal eller ctrl-d för att avsluta: ");
            
            if(scanf("%s", bigNumberString2)<0){
                break;
            }else{
                bigInt * bigNumber2 = createBigInt(bigNumberString2);
                
                if(bigNumber2 == NULL){
                    freeList(bigNumber1);
                    continue;
                }
                printf("Summan är: ");
                sum = add(bigNumber1, bigNumber2, 0);
                sum = invert(NULL, sum);
                sum = clean(sum);
                saveToFile(sum);
                sum = invert(NULL, sum);
                
                printBigInt(sum);
                freeList(bigNumber1);
                freeList(bigNumber2);
                freeList(sum);
            }
        }
    }
    return 0;
}