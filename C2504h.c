//C2504h
//3430302/90003
//Biga V.S.
//17.03.2020
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void savePnt(int *pArr);
void swapInt(int *a, int *b, int *counter);
int main()
{
  int i,j,counter=0;
  int *pArr[10], iArr[9];

  printf("C2504h\n");
  printf("3430302/90003\n");
  printf("Biga V.S.\n");
  printf("18.03.2020\n");
  printf("\n");

  srand (time(NULL));
  for (i=0; i<9; i++)
    {
      iArr[i]=rand()%1000;
      pArr[i]=&iArr[i];
    }
  savePnt(pArr[0]);
  pArr[9]=NULL;
  for(i=0; i<8; i++)
    {
        for(j=i+1; j<9; j++)
          {
            if ( *(pArr[j]) < *(pArr[i]) ) swapInt( pArr[j], pArr[i], &counter );
          }
    }
  savePnt(pArr[0]);
  return 0;
}

void savePnt(int *pArr)
{
  int i;
  FILE* outfile=fopen("output2504h.txt","a+");//create file or open and write in end of file
  //printf("%s %c %s \n","    Adress",'\t',"     Value");
  fprintf(outfile, "%s %c %s \n","    Adress",'\t',"     Value");
  for (i=0;i<9;i++)
    {
      //printf("%10p %s %10i \n",pArr+i,"\t",*(pArr+i) );
      fprintf(outfile, "%10p %s %10i \n",pArr+i,"\t",*(pArr+i) );
    }
  fclose(outfile);
}
void swapInt(int *a, int *b, int *counter)
{
  //if (*a==*b) return;
  *a=*a^*b;
  *b=*a^*b;
  *a=*a^*b;
  *counter = *(counter) +1;
}
