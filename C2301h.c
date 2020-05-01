//C2301h
//3430302/90003
//Biga V.S.
//04.03.20
//
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int M, N, i, j;
  printf("%s\n","C2301h" );
  printf("%s\n","3430302/90003" );
  printf("%s\n","Biga V.S." );
  printf("%s\n \n","04.03.20" );

  FILE* inf = fopen("input2301h.txt","rt");
  if( inf == NULL)
  {
    printf("%s\n", "ERROR. File not found." );
    return -1;
  }

  fscanf(inf, "%i %i", &M, &N);
  printf("\n %s \n %i \t %i \n \n","Value:", M, N );
  int *pM = &M, *pN = &N;
  int Matrix[M][N], *pMatrix[M][N];

  for (i=0; i<M; i++)
  {
    for (j=0; j<N; j++)
    {
      fscanf(inf, "%i", &Matrix[i][j]);
      pMatrix[i][j] = &Matrix[i][j];
      printf("%i\t",Matrix[i][j]);
    }
    printf("\n");
  }

  printf("\n \n %s \n %p \t %p \n \n","Adresses:", pM, pN );
  for (i=0; i<M; i++)
  {
    for (j=0; j<N; j++)
    {
      printf("%p\t",pMatrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
