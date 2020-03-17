#include "stdlib.h"
#include "stdio.h"
void vecSwap(const int iLength, int *iVec)
{
  int i, marker;
  if (iLength==1) return;
  else marker=(int)iLength/2 - 1;
  for(i=0; i<=marker; i++)
    {
      if ( *(iVec+i)==*(iVec+iLength-1-i) ) continue;
      else {
            *(iVec+i) ^ *(iVec+iLength-1-i);
            *(iVec+i) ^ *(iVec+iLength-1-i);
            *(iVec+i) ^ *(iVec+iLength-1-i);
           }
    }
  return;
}
void printVector(const int iLength, int *iVec)
{
  int i,tmp;
  for (i=0; i<iLength; i++)
    {
      tmp=*(iVec+i);
      //printf("%i \t", *(iVec+i) );
      printf("%i \t", tmp);
    }
}
int main()
{
  int tmp, num=0;
  FILE* inf;

  printf("C2502h\n");
  printf("3430302/90003\n");
  printf("Biga V.S.\n");
  printf("17.03.2020\n");
  printf("\n");

  inf = fopen("inputC2502h.txt", "rt");
  if (inf==NULL)
    {
      printf("%s\n","ERROR. File not found." );
      return -1;
    }

  do
    {
      fscanf(inf, "%i", &tmp);
      num = num+1;
    } while (!feof(inf));
    printf("%i \n",num );

  fclose(inf);
  if (num==0)
    {
      printf("%s\n","ERROR. Clean file." );
      return 1;
    }
  printf("%s\n","File will open" );
  inf = fopen("inputC2205h.txt", "rt");
  int Vector[num];
  for (tmp=0; tmp < num; num++)   fscanf(inf, "%i", &Vector[tmp]);
  printf("%s\n","File will open" );

  printVector(num, &Vector[0]);
  vecSwap (num, &Vector[0]);
  printVector(num, &Vector[0]);
  return 1;
}
