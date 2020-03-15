//C2205h
//3430302/90003
//Biga V.S.
//17.02.2020
//
#include  <stdio.h>
#include  <stdlib.h>
int main()
{
  int i,j,d=0,fl=1,num=0;
  char Ch_tmp;
  FILE* inf;

  printf("C2205h\n");
  printf("3430302/90003\n");
  printf("Biga V.S.\n");
  printf("17.02.2020\n");
  printf("\n");

  inf = fopen("inputC2205h.txt", "rt");
  if (inf==NULL)
    {
      printf("%s\n","ERROR. File not found." );
      return -1;
    }

  do
    {
      fscanf(inf, "%c", &Ch_tmp);
      if (Ch_tmp<='9' && Ch_tmp>='0' )
        {
              if (fl==1) // fl=1 если предыдущий символ -табуляция
                {
                  num = num + 1;
                  fl = 0;
                }
        }
      else fl=1;
    } while (!feof(inf));

  fclose(inf);
  if (num==0)
    {
      printf("%s\n","ERROR. Clean file." );
      return 1;
    }

  int Arr[2][num];// 1-я строка - содержит вектор, 2-я содержит 0 и 1 -
  inf = fopen("inputC2205h.txt", "rt"); // 0 под числом означает, что оно не имеет дубля в векторе

  for(i=0; i<num; i++)
    {
      fscanf(inf,"%i",&Arr[0][i]);
      Arr[1][i]=0;
    }

  // печать вектора
  for (i=0; i<num; i++)
      {
        printf("%i \t", Arr[0][i]);
      }
  printf("\n");
  // ищет повторяющиеся элементы справо от текущего в векторе, если находит ставит метку в соответствующие элементы в 2-й строке
  for (i=0; i<=num-2; i++)
    {
        for (j=i+1; j<=num-1; j++)
            {
                if  ( Arr[0][i] == Arr[0][j] && i!=j)
                    {
                      Arr[1][i]=1;
                      Arr[1][j]=1;
                    }
            }
    }
  for(i=0; i<num; i++) if(Arr[1][i]==0) d=d+1;
  printf("%s %i %s %i %s \n","В векторе ", num , " чисел, из них ",d, " - различны." );
  return 0;
}
