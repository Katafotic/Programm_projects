//C2503h
//3430302/90003
//Biga V.S.
//18.03.2020
//
#include <stdlib.h>
#include <stdio.h>
//вместо отстутстующей conio.h
//#include <conio.h>
#include <ncurses.h>
#include <stdio.h> //на всякий случай
#define LENGTH 10
void pushStack(char ch_tmp,int *pHead, int *counter_write);
void popStack(int *pHead,int *First_in_Stack, int *counter_read);
int main()
{
  int counter_write=0,counter_read=0, vStack[LENGTH];
  int *pHead=&vStack[0];
  char ch_tmp;
  printf("%s\n","C2503h" );
  printf("%s\n","3430302/90003" );
  printf("%s\n","Biga V.S." );
  printf("%s\n","18.03.2020" );
  while ( (ch_tmp=getchar() )!='\t' )
      {
      //ch_tmp=getch();
      //ch_tmp=getchar();
      if ( ( ch_tmp==' ' )||(ch_tmp=='\t') ) break;
      pushStack(ch_tmp, pHead, &counter_write);
    }
  pHead = pHead - 1;
  while (counter_read!=counter_write)
    {
      popStack(pHead, &vStack[0], &counter_read);
    }

  return 0;
}

void pushStack(char ch_tmp, int *pHead, int *counter_write)
{
  *counter_write = *counter_write +1;
  *pHead = (int) ch_tmp;
  if (*counter_write==LENGTH )
    {
      printf("%s\n","Stack is overflow." );
      return ;
    }
  else pHead=pHead+1;
}

void popStack(int* pHead, int *First_in_Stack, int *counter_read) //выводит на экран элемент, предшествующий элементу, на который указывает pHead
  {
    char ch_tmp;
    if (*(pHead)==*First_in_Stack)
      {
        printf("%s\n", "Stack is empty");
        exit(0);
      }
    ch_tmp = *(pHead-1);
    printf("%c \t", ch_tmp);
    pHead = pHead - 1;
    *counter_read = *counter_read + 1;
  }
