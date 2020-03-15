//C2204h
//3430302/90003
//Biga.V.S.
//15.02.2020

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    double matrix_2[4][4];
    double matrix_1[4][4] = { 11.0, 12.0, 13.0, 14.0,
                              21.0, 22.0, 23.0, 24.0,
                              31.0, 32.0, 33.0, 34.0,
                              41.0, 42.0, 43.0, 44.0
                            } ;


  printf("C2204h\n");
  printf("3430302/90003\n");
  printf("Biga.V.S..\n");
  printf("15.02.2020\n");
  printf("\n");


  //Matrix_ixj
  for(j=0; j<4; j++)
    {
        for(i=0; i<4; i++)
        {
            matrix_2[j][i] = matrix_1[i][j];
        }
    }

  for(i=0;i<4;i++) //проход по строкам
    {
        for(j=0;j<4;j++) //проход по столбцам в строке матрицы
        {
            printf("%5.1f ",matrix_1[i][j],"   ");
            if (j==3) printf("\t");
        }

        for(j=0;j<4;j++)
        {
            printf("%5.1f",matrix_2[i][j],"   ");
            if (j==3) printf("\n");
        }
    }

    return 0;
}
