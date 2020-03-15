//C2203h
//3430302/90003
//Biga.V.S.
//15.02.2020

//celsius ---> farentgein
#include <stdio.h>
#include <stdlib.h>

int main()
{

float  cels = -40;

  printf("C2203h\n");
  printf("3430302/90003\n");
  printf("Biga.V.S..\n");
  printf("15.02.2020\n");
  printf("\n");

printf("  C  -->  F  \n");
do
{
  //far=cels*9/5.+32;
    printf("%5.1f", cels ,"\t");
    printf("%5.0f \n", cels*9 /5.0 +32);
    cels=cels+10;
} while(cels <= 200);

  return 0;
}
