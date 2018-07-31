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
#define SIZE 25
#define NUM 9
void printOpenMessageForSodokoSize();
void printOpenMessageForSodokoSolution();
void printValidSolution();
void printBadSolution();
int checkCols(int arr[SIZE][SIZE], int size);
int checkRows(int arr[SIZE][SIZE], int size);
int checkBooleanArray(bool arr[], int size);
int checkSquares(int arr[SIZE][SIZE], int size, int sqrt);
int checkSubSquares(int arr[SIZE][SIZE], int i, int j, int sqrt);
int sqrtSoduko(int a);


/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    int matrix[SIZE][SIZE];
    int size, i, j;
    bool valid = true;
    printOpenMessageForSodokoSize();
    scanf("%d", &size);
    int root=sqrtSoduko(size);
    printOpenMessageForSodokoSolution();
    /*Recieve input*/
    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
        {
            if(scanf("%d", &matrix[i][j])<1) return 1;
        }
    /*Using top down design with functions*/
    if(checkRows(matrix, size)==1 || checkCols(matrix, size)==1)
    {
        valid = false;
    }
    if(checkSquares(matrix, size, root) == 1)
        valid =false;
    if(valid)
        printValidSolution();
    else
        printBadSolution();
    return 0;
}
void printOpenMessageForSodokoSize(){
    printf("Please enter the size of your soduko:\n");
}
void printOpenMessageForSodokoSolution(){
    printf("Please enter your solution:\n");
}
void printValidSolution(){
    printf("Valid solution!\n");
}
void printBadSolution(){
    printf("Bad solution!\n");
}
int sqrtSoduko(int a)
{
    if(a<0)
        return -1;
    if(a == 0)
        return 0;
    if(a == 1)
        return 1;
    int num=2;
    if(num*num == a)
        return num;
    /*Continue loop as long as squared value less than number*/
    while(num*num < a )
    {
        num++;
        if(num*num == a)
            return num;
    }
    return -1;
}
int checkBooleanArray(bool arr[], int size)
{   int k;
    for(k=0; k<size; k++)
        {
            if(arr[k] == false)
                return 1;
        }
    return 0;
}
int checkSquares(int arr[SIZE][SIZE], int size,int sqrt)
{
        /*Move square around*/
    int i, j;
    for(i=0; i<size; i+=sqrt)
    {
        for(j=0; j<size; j+=sqrt)
        {
            if(checkSubSquares(arr, i, j, sqrt) == 1)
                return 1;
        }
    }
    return 0;
}
int checkSubSquares(int arr[SIZE][SIZE], int i, int j, int sqrt)
{
            int l, k;
            bool num[SIZE] = {0};
            /*Check each square*/
            for(l=i; l<(i+sqrt); l++)
                {/*Incrament until index+root value*/
                for(k=j; k<(j+sqrt); k++)
                    {

                    num[arr[l][k]-1] = true;
                    }
                }
            if(checkBooleanArray(num, (sqrt*sqrt)) == 1)
                return 1;
            return 0;
}
int checkCols(int arr[SIZE][SIZE], int size)
{       int temp;
        bool check[SIZE] = {0};
        for (int j=0; j<size ; j++){
         for (int i=0 ;i<size ;i++){
            temp = arr[j][i];
            check[temp-1] = true;

         }
        if(checkBooleanArray(check, size) == 1)
                return 1;
    }
    return 0;
}


int checkRows(int arr[SIZE][SIZE], int size)
{
    /*Same as checkCols but change of indices*/
        int temp;
        bool check[SIZE]= {0};
        for (int j=0; j<size ; j++){
         for (int i=0 ;i<size ;i++){
            temp = arr[i][j];
            check[temp-1] = true;

         }
        if(checkBooleanArray(check, size) == 1)
                return 1;
    }
    return 0;
}
