//C2305h
//3430302/90003
//Biga V.S.
//04.03.20
//
#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>

#define Vector_type int

void double_vector_print(int length, Vector_type *Vector);
Vector_type* search(int *length, Vector_type *Vector);
int main()
{
  printf("%s\n","C2305h" );
  printf("%s\n","3430302/90003" );
  printf("%s\n","Biga V.S." );
  printf("%s\n \n","04.03.20" );

  printf("%s\n", "Default object Vector have integer type, read value Vector from file \"input2305h.txt\"  ");
  printf("%s \n \n", "Default Vector length = 5 ");

  int length = 5;
  Vector_type *SubVector, Vector[length];



  int i=0;
  FILE* inf = fopen("input2305h.txt","rt");
  if (inf == NULL) {
    printf("%s\n","ERROR. File \"input2305h.txt\" with Vector not found." );
    return -1;
  }
  for(i=0; i<length ; i++) {
    fscanf(inf, "%i", &Vector[i] );
    // fscanf("%f", &Vector[i]);
  }
  fclose(inf);


  printf("%s\n", "Vector:");
  vector_print(length, &Vector);
  printf("%s\n","SubVector:" );
  SubVector = search(&length, &Vector);
  vector_print(length, SubVector);
  return 0;
}

void vector_print(int length, Vector_type *Vector)
{
  int i;
  for(i=0; i<length ; i++) {
  printf("%i \t", *(Vector+i) );
  //printf("%12.5f \t", *(Vector+i) );
  }
  printf("\n");
  return;
}

Vector_type* search(int *length, Vector_type *Vector)
{
  Vector_type max_el = *Vector, min_el = *Vector;
  int i;
  if (*length == 1 ) return Vector;

  // поиск значений наибольшего и наименьшего элемента
  for(i=0; i < (int)*(length); i++)
  {
    if ( *(Vector + i) >= max_el )  max_el = *(Vector+i);
    if ( *(Vector+i) <= min_el )  min_el = *(Vector+i);
  }
  if (max_el == min_el) return Vector;

  // проверка случая, когда наименьший и/или наибольший элемент повторяются
  int fl_1=0,fl_2=0;
  int first_max=0, first_min=0, last_max=0, last_min=0;
  // для доступа к соответствующему элементу : *(Vector+VARIABLE)
  for(i=0; i < *(length); i++)
  {

    if ( (*(Vector+i) == max_el) and first_max==0 )
    {   // для случая, когда несколько наибольших элементов стоят в начале
        if (i==0)   fl_1=1;   // first_max == 0;
        if (fl_1!=1)  first_max = i;
    }
    if ( (*(Vector+i) == max_el) )   last_max = i;


    if ( (*(Vector+i) == min_el) and first_min==0 )
    {   // для случая, когда несколько наименьших элементов стоят в начале
        if (i==0)   fl_2=1;   // first_min == 0;
        if (fl_2!=1) first_min = i;
    }
    if ( (*(Vector+i) == min_el) )   last_min = i;
  }

  // если подвектор можно выделить 2 способами: (max->min)/(min->max), выбирает (max->min)
  // определение порядка в котором расположены элементы подвектора
  if ( first_max < last_min ) // по убыванию
  {
    *length = last_min - first_max + 1;
    return Vector + first_max ;
  }

  if (first_min < last_max) // по возрастанию
  {
    *length = last_max - first_min + 1;
    return Vector + first_min ;
  }
}
