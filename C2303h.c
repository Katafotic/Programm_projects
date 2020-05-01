//C2303h
//3430302/90003
//Biga V.S.
//04.03.20
//
#include <stdlib.h>
#include <stdio.h>
int swap(float *pfloat_1, float *pfloat_2);
int main()
{
  printf("%s\n","C2303h" );
  printf("%s\n","3430302/90003" );
  printf("%s\n","Biga V.S." );
  printf("%s\n \n","04.03.20" );

  float vfloat_1 = 11.3, vfloat_2 = -46.2;
  float *pfloat_1 = &vfloat_1, *pfloat_2 = &vfloat_2;
  int result = swap(pfloat_1, pfloat_2);
  printf("%s %i \n","Result: ",result );
  return 0;
}

int swap(float *pfloat_1, float *pfloat_2)
{
  float result = *pfloat_1 + *pfloat_2;
  printf("%s\n %f \t %f \n","Before swap:",*pfloat_1,*pfloat_2 );
  float tmp = *pfloat_1;
  *pfloat_1 = *pfloat_2;
  *pfloat_2 = tmp;
  printf("%s\n %f \t %f \n \n","After swap:", *pfloat_2,*pfloat_1 );
  result = result - (*pfloat_1 + *pfloat_2);
  return (int)result;
}
