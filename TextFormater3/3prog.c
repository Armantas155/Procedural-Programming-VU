// Create a function that deletes words from an input file whose middle symbol is a number
// Data and result file names are given through command line arguments 
// Armantas Pikšrys 3.9 task

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void validateResultFile(char resName[]);
void rearrangeString(char stringBuff[]);
void removeWord(char stringBuff[], char wordBuff[], int wordStart, int wordIndex);

#define maxChar 256

int main(int argc, char *argv[])
{
    /* Opening files and validating input */
    if(argc < 3)
    {
        printf("Error! Data or result file is not specified!\n");
        exit(1);
    }

    validateResultFile(argv[2]); //validate that result file is of .txt format
    
    FILE *fi, *fo; // fi - input file, fo - output file
    fi = fopen(argv[1], "r");
    fo = fopen(argv[2], "w");

    if(fi == NULL || fo == NULL)
    {
        printf("Error! Could not open data file\n");
        exit(1);
    }
    /* Read file and deletes words whose middle symbol is a number */

    char stringBuff[maxChar];
    while(fgets(stringBuff, maxChar, fi) != NULL) //Read file until the end
    {
        if(strlen(stringBuff) == maxChar - 1) //Checking buffer limit (255)
        {
            stringBuff[maxChar - 2] = '\n'; //If exceeded buffer limit, add newline at the end
            while(fgetc(fi) != '\n');
        }
        rearrangeString(stringBuff);
        fprintf(fo, "%s", stringBuff); //Write to result file
    }

    printf("\nTask completed!\n");

    fclose(fi);
    fclose(fo);
    return 0;
}

void validateResultFile(char resName[])
{
    char buff[] = ".txt";
    int foLength = 0, counter = 4; // fo - output file

    foLength = strlen(resName); 
    if(foLength > 4)
    {
        for(int i = 0; i < 4; ++i)
        {
            if(buff[i] != tolower(resName[foLength - counter])) //Validating that the specified result file is of ".txt" format
            {
                printf("Error! Could not create result file (needs to be .txt format)\n");
                exit(1);
            }
            --counter;
        }
    }
    else
    {
        printf("Error! Could not create result file (needs to be .txt format)\n");
        exit(1);
    }

    return ;
}

void rearrangeString(char stringBuff[])
{
    int wordIndex = 0, stringIndex = 0, wordStart = 0;
    char wordBuff[maxChar];

    stringIndex = strlen(stringBuff) - 1; //substract 1 so that newline does not disappear

    for(int i = 0; i < stringIndex; ++i)
    {
        if(isspace(stringBuff[i]) || stringBuff[i + 1] == '\n')
        {
            if(stringBuff[i + 1] == '\n')
            {
                wordBuff[wordIndex] = stringBuff[i];
                ++wordIndex;
            }

            wordBuff[wordIndex] = '\0'; //close string

            if(wordIndex != 0)
            {
                if((wordIndex % 2) == 1 && isdigit(wordBuff[wordIndex / 2]))// delete only if middle symbol is a number
                {
                    removeWord(stringBuff, wordBuff, wordStart, wordIndex);
                    stringIndex -= (i - wordStart + 1); //substract the number of symbols we deleted
                    i = -1; //reset
                }
                wordIndex = 0;
            }
        }
        else
        {   
            if(wordIndex == 0) //new word
                wordStart = i;
            wordBuff[wordIndex] = stringBuff[i];
            ++wordIndex;
        }
    }
    return;
}

void removeWord(char stringBuff[], char wordBuff[], int wordStart, int wordIndex)
{
    int j;
    char *tempBuff =(char *)calloc(maxChar, sizeof(char));

    for(j = 0; stringBuff[j] != '\n'; ++j) //temporary string buffer
        tempBuff[j] = stringBuff[j];
    
    tempBuff[j] = '\n';

    for (int i = wordStart; stringBuff[i] != '\n'; ++i)
    {
        if(tempBuff[wordStart + wordIndex] == '\n') //if at the end of the words is a newline and not a space symbol, then do not delete it
            stringBuff[i] = stringBuff[i + wordIndex];
        else
            stringBuff[i] = stringBuff[i + wordIndex + 1];
    }
    
    free(tempBuff);
    return;
}