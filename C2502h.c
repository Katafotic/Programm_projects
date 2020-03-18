//C2502h
//3430302/90003
//Biga V.S.
//18.03.2020
//
#include <stdlib.h>
#include <stdio.h>

void vecSwap(const int iLength, int *iVec);
void printVector(const int iLength, int *iVec);

int main()
{
  int tmp, num=0;
  FILE* inf;
  char Ch_tmp;

  printf("C2502h\n");
  printf("3430302/90003\n");
  printf("Biga V.S.\n");
  printf("18.03.2020\n");
  printf("\n");

  inf = fopen("inputC2502h.txt", "rt");
  if (inf==NULL)
    {
      printf("%s\n","ERROR. File not found." );
      return -1;
    }

  int fl=1;
  do // считыввает число элементов
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
  inf = fopen("inputC2502h.txt", "rt");
  int Vector[num];

  for (tmp=0; tmp < num; tmp++)     fscanf(inf, "%i", &Vector[tmp]);
  fclose(inf);
  printf("\n");

  printVector(num, &Vector[0]);
  vecSwap (num, &Vector[0]);
  printVector(num, &Vector[0]);
  return 0;
}

void vecSwap(const int iLength, int *iVec)
{
  int i, marker;
  if (iLength==1) return;
  else marker=(int)iLength/2 - 1;
  for(i=0; i<=marker; i++)
    {
      if ( *(iVec+i)==*(iVec+iLength-1-i) ) continue;
      else {
            *(iVec+i) = *(iVec+i)  ^  *(iVec+iLength-1-i);
            *(iVec+iLength-1+i) = *(iVec+i)  ^  *(iVec+iLength-1-i);
            *(iVec+i) = *(iVec+i)  ^  *(iVec+iLength-1-i);
           }
    }
  return;
}
void printVector(const int iLength, int *iVec)
{
  int i;
  for (i=0; i<iLength; i++)    printf("%i \t", *(iVec+i) );
  printf("\n");
}
