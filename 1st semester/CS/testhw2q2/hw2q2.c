/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/

#define LETTER_LEN 'z'-'a'+1

void printThreeDigitsOpenMessage();
void printResults(int avg,int rootOfMinNum,int avgPowTwoRootOfMinNum);
void printCharactersOpenMessage();
void printDataPerGivenCharAsInput(char ch,int numberOfTimesAppeared);
void printNumberOfOtherCharsAppeared(int numberOfOtherCharsAppeared);
void printCharacters(int arr[LETTER_LEN]);
void characterAnalysis();
void printCharactersOpenMessage();


/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    characterAnalysis();
  return 0;
}
void printThreeDigitsOpenMessage()
{
    printf("Please enter three integers:\n");
}

void printResults(int avg,int rootOfMinNum,int avgPowTwoRootOfMinNum){
    printf("%d %d %d\n",avg,rootOfMinNum,avgPowTwoRootOfMinNum);
}

void printCharactersOpenMessage(){
    printf("Please enter your character set:\n");
}

void printDataPerGivenCharAsInput(char ch,int numberOfTimesAppeared){
    printf("letter %c appeared %d time in the given set of characters\n",ch,numberOfTimesAppeared);
}
void printNumberOfOtherCharsAppeared(int numberOfOtherCharsAppeared){
    printf("number of other characters in the given set was: %d\n",numberOfOtherCharsAppeared);
}
void characterAnalysis()
{
/*print message*/
printCharactersOpenMessage();
char ch;
int letter[LETTER_LEN]={0};
int counter=0;
/*get characters*/
while( scanf("%c", &ch) == 1 )
{
    if( ch == ';')
        break;
    if(ch>= 'a' && ch<='z') /*count how many times each char showed up*/
    {
    letter[ch-'a']++; /*correct*/
    }
    else /*count how many non a-z*/
    {
    counter++;
    }
}
printCharacters(letter);
/*print using func*/
printNumberOfOtherCharsAppeared(counter);
}
void printCharacters(int arr[LETTER_LEN])
{
    int curr;
    /*print using func*/
    for(int i=0; i<LETTER_LEN; i++)
    {
        curr = 'a'+i;
        printDataPerGivenCharAsInput(curr, arr[i]);
    }
}
