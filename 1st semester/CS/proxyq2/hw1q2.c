
/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/



/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    char c, seq;
    int counter=0;
    printf("Enter char to count:\n");
    scanf("%c", &c);
    if(c == 's' || c == 'S' || c=='m' || c=='M')
    {
    printf("Enter the chars sequence:\n");
    do{
            scanf("%c", &seq);
            if(seq == c)
            {
                counter++;
            }
    } while( seq != '$' );
    if(counter>0)
    {
            printf("The char with ASCII code %d appeared %d times.\n", c, counter );
    }
    }

  return 0;
}