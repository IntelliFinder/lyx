/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
int sum_num(int a[], int sum, int size);
void swap(int* a, int* b);
int bubble(int a[], int n);
int bubble_sort(int a[], int n, int sum);
int quick_find(int a[], int n, int sum);

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
  /*input array*/
  int size=0, sum=0;
  printf("Please enter length:\n");
  scanf("%d", &size);
  int* arr=(int*)malloc(sizeof(int)*size);
  printf("Please enter array:\n");
  for(int i = 0; i<size; i++)
    scanf("%d", (arr+i));
  printf("Please enter sum:\n");
  scanf("%d", &sum);
  /*bubble sort*/
  if(bubble_sort(arr,size, sum) == 1)
  {
      printf("Such elements do exist.");
  }else {printf("Such elements do not exist.");}
  free(arr);
  return 0;
}
void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
int bubble(int a[], int n)
{
    int i, swapped=0;
    /*print array*/
    for(i=1; i < n; i++)
    {
        if(a[i-1]>a[i])
        {
            swap(&a[i], &a[i-1]);
            swapped=1;
        }
    }
    return swapped;
}
int quick_find(int a[], int n, int sum)
{

    for(int i =0; i< n; i++)
    {
        int b=i+1, t=n-1;
        int comp = a[i];
        while(  b<t )
        {
            if(a[b] + a[t]+ comp == sum)
            {
                return 1;
            }
        //if triplet < sum increment left index
            if(a[b] + a[t]+ comp < sum)
               {
                b++;
               }
        //if triplet > sum decrement right index
            if(a[b] + a[t]+ comp > sum)
            {
                t--;
            }
        }
    }
    return 0;
}
int bubble_sort(int a[], int n, int sum)
{
    int not_sorted = 1, n2=n;
    while((n>0) && (not_sorted))
    {
        not_sorted = bubble(a, n--);
    }
    /*flip array
    for(int i=0; i < n2 ; i++)
    {
        int temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1]= temp;
    }*/
    return quick_find(a, n2, sum);
}
