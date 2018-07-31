/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRINGS 10
#define MAX_STR_LEN 50

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    char* palindromes[MAX_STRINGS];
    int len=0,array[MAX_STRINGS] = {0}, counter=0;
    char ch[MAX_STRINGS][MAX_STR_LEN]={{'\0'}};
    /*Get char until maxSize or end of input*/
    for(int i=0; i<MAX_STRINGS; i++)
    {
        scanf("%s", ch[i]);
    }
    /*Convert all to uppercase*/
    for(int i=0; i<MAX_STRINGS; i++)
    {
        for(int j=0; j<MAX_STR_LEN; j++)
        {
            if((ch[i][j]>='a'&&ch[i][j]<='z'))
                ch[i][j]+= 'A'-'a';
        }
    }
    /*Check each word if polindrom - case insensitive*/
    for(int i=0; i<MAX_STRINGS; i++)
    {
        len = strlen(ch[i]); //w/o null character
        printf("%d", len);
        for(int j=0; j<(len/2); j++)
        {
            if(ch[i][j] != ch[i][len-j-1])
            {
                array[i] = 1;
                break;
            }/*condition for polindrom*/
        }
    }
    for(int i=0; i<MAX_STRINGS;i++)
    {
        if(array[i]==0)
        {   /*extra room for null*/
            char* temp_array = (char*)malloc(sizeof(char)*(strlen(ch[i])+1));
            printf("%s", temp_array);
            if(temp_array==NULL)
            {
            printf("Malfunction");
            return -1;
            }
            for(int j=0; j<MAX_STR_LEN; j++)
            {
                temp_array[j] = ch[i][j];
                printf("%c", temp_array[j]);
            }
            /*insert word into array*/
            strcpy(palindromes[counter], temp_array);

            counter++;
            free(temp_array);
        }

    }
  return 0;
}

