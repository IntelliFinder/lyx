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
int average(int a, int b, int c);
int min(int a, int b);
int absolute(int a);
int root(int a);
int power(int base, int power);
/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    int avg, rootOfMinNum, avgPowRootMinNum, a, b, c;
    printThreeDigitsOpenMessage();
    scanf("%d %d %d", &a, &b, &c);
    avg = average( a, b, c);
    int abss = absolute(min(min(a, b), c));
    rootOfMinNum  = root(absolute(min(min(a,b), c)));
    avgPowRootMinNum=power(average(a, b, c), abss );
    printResults(avg, rootOfMinNum, avgPowRootMinNum);
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
int average(int a, int b, int c)
{
    return (int)(a+b+c)/3;
}
int min(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}
int root(int a)
{
    if(a<0) /*Not sure if necessary*/
        return -1;
    if(a==0)
        return 0;
    if(a == 1)
        return 1;
    int num=2;
    if(num*num == a)
        return num;
    while(num*num < a )
    {
        num++;
        if(num*num == a)
            return num;
    }
    return -1;
}
int power(int base, int power)
{
    if(base == 0 && power ==0)
        return 1;
    if(base<0 || power <0)
        return -1;
    int i, val=base;
    for(i=1; i<power; i++)
    {
        val *= base;
    }
    if(val> 1000000000)
        return -1;
    return val;

}
int absolute(int a)
{
    if(a>=0)
        return a;
    else
        return -1*a;
}
void characterAnalysis()
{
/*print message*/
printCharactersOpenMessage();
char ch;
int letter[LETTER_LEN] = {0};
int counter=0;
/*get characters*/
while( scanf("%c", &ch) != EOF )
{
    if(ch>= 'a' && ch<='z') /*count how many times each char showed up*/
    {
    letter[ch-'a'] +=1;
    }
    else /*count how many non a-z*/
    {
    counter++;
    }
}
printCharacters(letter);
/*print using func*/
printNumberOfOtherCharsAppeared(counter-1);
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
