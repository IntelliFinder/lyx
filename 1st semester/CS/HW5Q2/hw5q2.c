/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define N 4
#define NUM 5


/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
void pathFinder(int cities[N][N], int index, int used[N],
                            int path[N], int best_path[N], int* min, int dest);
void check(int cities[N][N], int path[N], int best_path[N], int* min, int index);
void print_array(int word[N], int source);

/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
  /*
  Plan:
  1. N values in matrix
  2. restriction: first and last index are source&destination, respectively
  3. calculate dest. : value in array
  4. combinations 1-N each column
  5. compare with cities[source][dest] if length longer than say no
  6. check if already used (already past through and creates loop)
  */
  int cities[N][N]={{NUM}}, used[N]= {0},path[N] ={NUM},
            source=0, dest=0, m=0;//best_path[N]={NUM};
  int *min;
  min = &m;
  printf("Please enter roads matrix:\n");
  for(int i=0; i < N; i++)
    for(int j=0; j < N; j++)
        scanf("%d", &cities[i][j]);
  printf("Please enter source city:\n");
  scanf("%d", &source);
  printf("Please enter destination city:\n");
  scanf("%d", &dest);
  *min = cities[source][dest]; //default min
  int best_path[N] = {source, dest, NUM, NUM};
  path[0] = source;
  pathFinder(cities, 1, used, path, best_path, min, dest);
  printf("The shortest path is:\n");
  print_array(best_path, source);
  return 0;
}
void pathFinder(int cities[N][N], int index, int used[N],
                    int path[N], int best_path[N], int* min, int dest)
{
   if(path[index-1]==dest ) {
      check(cities, path, best_path, min, index);
      return;
   }
   int i;
   for(i = 0; i < N; i++) {
      if(used[i]) continue;
      path[index] = i; //breaks after first element
      used[i] = 1;
      pathFinder(cities, (index + 1), used, path, best_path, min, dest);
      used[i] = 0;
   }
   return;
}
void check( int cities[N][N], int path[N], int best_path[N],
                                            int* min, int index)
{
    int sum = 0;
    for(int i=0; i< (index-1); i++)
    {
        sum += cities[path[i]][path[(i+1)]];
    }
    if( *min > sum )
    {
        /*for(int i=0; i < N; i++)
        {
                printf("%d, ", path[i] );
        }*/
        //printf("Sum smaller than min\n");
        for(int i=0; i<index; i++)
        {
            best_path[i] = path[i];
        }
        for(int i=0; i<(N-index); i++)
        {
            best_path[N-i-1] = NUM;
        }
        *min = sum;
    }
}
void print_array(int word[N], int source)
{
  printf("%d ", source );
  for(int i=0; i < N; i++)
  {
    if( word[i] != NUM  && word[i] != source)
        printf("%d ", word[i] );
  }
}
