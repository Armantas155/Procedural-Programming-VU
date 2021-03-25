#include <stdio.h>
#include <stdlib.h>

/* Procedural Task that searches a given integer number between inputed number pairs */
/* Armantas Pikšrys 2.3 task */

int getNum();
void printAll(int firstNumber[], int secondNumber[], int numberOfPairs, int integerNumber);

int main()
{
    int numberOfPairs, integerNumber, x; //x - used to swap the given number pair members

    printf("Enter, how many pairs you want to input: ");
    numberOfPairs = getNum();
    
    if(numberOfPairs < 0)
        numberOfPairs = 0;

    int firstNumber[numberOfPairs], secondNumber[numberOfPairs];
    
    for(int i = 0; i < numberOfPairs; i++)
    {
        printf("Enter %d pair of integers\n", i + 1);
        firstNumber[i] = getNum();
        secondNumber[i] = getNum();

        if(abs(firstNumber[i]) > abs(secondNumber[i])) //swaping so that the smaller number is first
        {
            x = firstNumber[i];
            firstNumber[i] = secondNumber[i];
            secondNumber[i] = x;
        }
    }

    printf("Enter an integer that will searched between integer pair intervals: ");
    integerNumber = getNum();
    printAll(firstNumber, secondNumber, numberOfPairs, integerNumber);

    return 0;
}

int getNum()
{
	int number = 0, index = 0;
	while(index == 0)
    {
        if((scanf("%d", &number) == 0) || (getchar() != '\n')) //If an integer is not read or there is no \n (enter) symbol, then the if statement is true
        {    
            printf("Not a correct number, try again!\n");
            while(getchar() != '\n'); 
        }
        else index = 1;
	}
    return number;
}

void printAll(int firstNumber[], int secondNumber[], int numberOfPairs, int integerNumber)
{
    int suitablePairs = 0;
    printf("Suitable number pairs:\n");
    for(int i = 0; i < numberOfPairs; i++)
    {
        if(integerNumber >= abs(firstNumber[i]) && integerNumber <= abs(secondNumber[i]))
        {
            printf("%d %d\n", firstNumber[i], secondNumber[i]);
            suitablePairs++;
        }
    }
    printf("In total number of suitable pairs is %d", suitablePairs);
    return;
}