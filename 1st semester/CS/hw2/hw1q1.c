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
    int weight, pure=0, counter=0;
    double average=0;
    printf("Welcome, please enter the weights of each ingredient:\n");
    scanf("%d", &weight);
    while(weight>-1)
    {
        counter++;
        pure += 10;
        printf("Welcome, please enter the weights of each ingredient:\n");
        scanf("%d", &weight);
        if(weight<= -1)
            break;
        average += weight;
    }
    if (counter>10)
    {
        printf("Too many ingredients.\n");
    } else if(counter < 3)
    {
        printf("Not enough ingredients.\n");
    }
    average /= counter;
    printf("The final product weighs %.3f pounds and is %d percent pure.\n", average, pure);
  return 0;
}
