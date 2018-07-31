/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
/*
The function recursively
*/
int secondLargest(int size, int* array, int* largest);

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    int size=0, largest=INT_MIN;
    printf("Please enter length:\n");
    /*Get array size*/
    scanf("%d", &size);
    /*get size*/
    if( size <= 1 )
        return 0;
    /*allocate array*/
    int* array = (int*)malloc(sizeof(int)*size);
    if(array == NULL)
        exit(0);
    printf("Please enter array:\n");
    for(int i=0; i<size;i++)
    {
        scanf("%d", &array[i]);
    }
    /*recursive function*/
    printf("The second-greatest is:\n");
    printf("%d", secondLargest(size, array, &largest));
    free(array);
  return 0;
}
int secondLargest(int size, int* array, int* largest)
{
    if( size==2 )
    {
        *largest = (array[0] > array[1]) ? array[0] : array[1];
        return (array[0] > array[1]) ? array[1] : array[0];
    }
    int second = secondLargest(size-1, array+1, largest);
    //if value is bigger than largest update largest
    if(array[0] > *largest)
        *largest = array[0];
    //if value is biggger than second and smaller than large
    return (array[0] > second && array[0] < *largest) ? array[0] : second;
}
