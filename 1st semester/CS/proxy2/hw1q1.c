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
int main() {
  int weight=0;
  double average;
  int arr;
  int i=0;
  printf("Welcome, please enter the weights of each ingredient:\n");
  scanf("%d", &arr);
  while( arr>=0 ) {
      i++;
      weight += arr;
      scanf("%d", &arr);
  }

  if (i>10)
    {
        printf("Too many ingredients.\n");
    } else if(i < 3)
    {
        printf("Not enough ingredients.\n");
    }
  if(i>=3 && i<=10){
  average = (double)(weight) / i;
  printf("The final product weighs %.3f pounds and is %d percent pure.\n", average, i*10);
  }

  return 0;
}
