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

void printGivenParamsToTheOutput(char ch,int asciiCode,int asciiCodePowTwo,int difference,int unitDigitOfDiff);
void printResults(int digitsCounter,int lettersCounter,int spacesCounter);
void calculateParams(char ch, char , bool first);
/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    char ch=0, prev=0;
    bool a=false, b=false;
    int digitsCounter=0, lettersCounter=0, spacesCounter=0;
    int ascii=0, asciiPowTwo=0, difference=0, unitDigitOfDiff=0;
    scanf("%c", &ch);
    while (ch != ';'){ /*Loop ends when user enters char*/
        ascii = ch;
        asciiPowTwo = ch*ch; /*Multiplication of chars*/
        difference = ch - prev;
        unitDigitOfDiff = difference%10;
        if (ch <= '9' && ch >= '0' ){
                digitsCounter++;
                a=true;
            }
        if (((ch <= 'Z' && ch >= 'A') || (ch <= 'z' && ch >= 'a')) && !a){
                lettersCounter++;
                b=true;
            }
        if (ch == ' ' && !b && !a){
                spacesCounter++;
            }
        a=false;
        b=false;
        /*Send to function to print data*/
        printGivenParamsToTheOutput(ch,ascii,asciiPowTwo,difference,unitDigitOfDiff);
        prev =ch;
        scanf("%c",&ch);
            }
    printResults(digitsCounter, lettersCounter, spacesCounter);
    return 0;
}

void printGivenParamsToTheOutput(char ch,int asciiCode,int asciiCodePowTwo,int difference,int unitDigitOfDiff)
{
    printf("%c%10d%10d%10d%10d\n",ch,asciiCode,asciiCodePowTwo,difference,unitDigitOfDiff);
}
void printResults(int digitsCounter,int lettersCounter,int spacesCounter){
    printf("Number of digits received: %d\n",digitsCounter);
    printf("Number of letters received: %d\n",lettersCounter);
    printf("Number of spaces received: %d\n",spacesCounter);
}
