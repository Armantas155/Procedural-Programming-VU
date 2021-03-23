#include <stdio.h>
#include <stdlib.h>

/* Armantas Pikšrys 7th task */

int getNum();

int main(){
    int g, num, kiek=0, tkiek=0, suma=0, san=1;

    printf("Enter an integer G, which will mark the end the sequence: ");

    g=getNum();
    do{
        printf("Enter an integer: ");
        num=getNum();
        kiek++;
        if(num < 0){
            suma+=num;
            san*=num;
        }
        else if(num > 0){
            tkiek++;
        }
    }while(num != g);

    printf("Number of members: %d\n",kiek);

    if(tkiek > 0) 
        printf("Positive number of members: %d\n",tkiek);
    else 
        printf("Positive numbers do not exist\n");

    if(suma != 0) 
        printf("Negative member sum: %d and multiplication: %d\n",suma,san);
    else 
        printf("Negative numbers do not exist\n");

	return 0;
}
int getNum(){
	int num=0, indeks=0;
	while(indeks == 0){
        //If an integer is not read or there is no \n (enter) symbol, then the if statement is true
        if((scanf("%d", &num) == 0) || (getchar() != '\n')){
            printf("Netinkamas skaicius, bandykite dar karta\n");
            while(getchar() != '\n'); 
        }
        else indeks=1;
	}

    return num;
}