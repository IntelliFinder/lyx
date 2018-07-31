/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
#define MAX_STRINGS 10
#define MAX_STR_LEN 50

int readPalindromes(char* palindromes[],int maxSize,int maxStrLen);
int  minimizedPalindromes(char* palindromes[],int size,char* miniOddPali[],int *sizeOdd,char* miniEvenPali[],int *sizeEven);
void printPalindromes(char* miniOddPali[],int sizeOdd, char* miniEvenPali[],int sizeEven);
void freeMemory(char* palindromes[],int size,char* miniOddPali[],int sizeOdd,char* miniEvenPali[],int sizeEven);
void upCase(char ch[MAX_STR_LEN], int maxStrLen);
int checkpoli(char ch[MAX_STR_LEN], int len);
void printAllocationError();
/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    char* words[MAX_STRINGS], *paliOdd[MAX_STRINGS], *paliEven[MAX_STRINGS];
    int sizeOdd=0, sizeEven=0;
    int numberOfPali=readPalindromes(words,MAX_STRINGS,MAX_STR_LEN);
    if(numberOfPali==-1)/*No palindromes*/
        return 1;
    minimizedPalindromes(words, numberOfPali, paliOdd, &sizeOdd, paliEven, &sizeEven);
    printPalindromes(paliOdd, sizeOdd, paliEven, sizeEven);
    freeMemory(words,numberOfPali,paliOdd, sizeOdd, paliEven, sizeEven);
    /*printf("%d\n", numberOfPali);
    printf("%d\n", mini);
    printf("%d\n", sizeEven);
    printf("%d\n", sizeOdd);*/
  return 0;
}
int readPalindromes(char* palindromes[],int maxSize,int maxStrLen)
{
    int counter=0;
    char ch[MAX_STR_LEN];
    /*Get char until maxSize or end of input*/
    for(int i=0; i<maxSize; i++)
    {
        if(scanf("%s", ch)==EOF) /*what is the end of input*/
            return counter;
        upCase(ch, maxStrLen);
        //printf("%s", ch);
        int len=0, poli = 1;
        len = strlen(ch); //w/o null character
        //printf("%d\n", len);
        poli = checkpoli(ch, len);
        if(poli==1)
        {
            /*extra room for null*/
            int length = (strlen(ch)+1);
            char *temp_array = (char*)malloc(sizeof(char)*length);
            if(temp_array==NULL)
            {
                printAllocationError();
                return -1;
            }
            for(int j=0; j<length-1; j++)
            {
                *(temp_array+j) = *(ch+j);
            }
            *(temp_array+length-1) = '\0';
            palindromes[counter] = temp_array;
            counter++;
        }
    }
    return counter;
}
int  minimizedPalindromes(char* palindromes[],int size,char* miniOddPali[],int *sizeOdd,char* miniEvenPali[],int *sizeEven)
{
    int num_poli=0;
    /*iterate over palindromes*/
    for(int i=0;i<size;i++)
    {
        /*dynamic allocation*/
        if((strlen(palindromes[i]))%2==0)
        {
            int evenLength = strlen(palindromes[i])/2;
            miniEvenPali[*sizeEven] = (char*)malloc(sizeof(char)*(evenLength+1));
            if(miniEvenPali[*sizeEven] == NULL)
            {
                printAllocationError();
                exit(0);
            }
            strncpy( miniEvenPali[*sizeEven], palindromes[i], evenLength);
            *(miniEvenPali[*sizeEven]+evenLength) = '\0';
            (*sizeEven)++;
            num_poli++;
        }
        if((strlen(palindromes[i]))%2==1)
        {
            int oddLength = (strlen(palindromes[i])/2) +1;
            miniOddPali[*sizeOdd] = (char*)malloc(sizeof(char)*(oddLength+1));
            if(miniOddPali[*sizeOdd] == NULL)
            {
                printAllocationError();
                exit(0);
            }
            strncpy(miniOddPali[*sizeOdd], palindromes[i], oddLength);
            *(miniOddPali[*sizeOdd]+oddLength) = '\0';
            (*sizeOdd)++;
            num_poli++;
        }
    }
    return num_poli;
}
void printPalindromes(char* miniOddPali[],int sizeOdd, char* miniEvenPali[], int sizeEven)
{
    int len;
    /*print odd*/
    for(int i=0; i<sizeOdd;i++)
    {
        len = strlen(miniOddPali[i]);
        printf("%s", miniOddPali[i]);
        for(int j=(len-2); j>=0; j--)
        {
            putchar(miniOddPali[i][j]);
        }
        printf("\n");
    }
    /*print even*/
    for(int i=0; i<sizeEven;i++)
    {
        len = strlen(miniEvenPali[i]);
        for(int j=(len-1); j>=0; j--)
        {
            putchar(miniEvenPali[i][j]);
        }
        printf("\n");
    }/*Note: Already converted to uppercase from read function*/
}
void upCase(char ch[MAX_STR_LEN], int maxStrLen)
{
        /*Convert all to uppercase*/
        for(int j=0; j<maxStrLen; j++)
        {
            if(*(ch+j)>='a'&&*(ch+j)<='z')
                *(ch+j) += 'A'-'a';
        }
}
int checkpoli(char ch[MAX_STR_LEN], int len)
{
        int j;
        for(j=0; j<(len/2); j++)
        {
            if(*(ch+j) != *(ch+len-j-1))
            {
                return 0;
            }/*condition for palindrome*/
        }
        return 1;
}
void freeMemory(char* palindromes[],int size,char* miniOddPali[],int sizeOdd,char* miniEvenPali[],int sizeEven)
{
    int i;
    //free up memory from pointers
    for(i=0; i<size;i++)
    {
        free(palindromes[i]);
    }
    for(i=0; i<sizeOdd;i++)
    {
        free(miniOddPali[i]);
    }
    for(i=0; i<sizeEven;i++)
    {
        free(miniEvenPali[i]);
    }

}
void printAllocationError(){
        printf("Memory Allocation Failed\n");
}
