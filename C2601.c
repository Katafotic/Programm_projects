// C2501                
// 3430302/x000x
// Safonov A.S.
// 09.03.2020

#include <stdio.h>
#include <stdlib.h>

void prnIntArr(int iRow, int iCol, int iArr[iRow][iCol]);
void ChangeArr(int* piRow, int* piCol, int *piArr);

int main()
{
    int i, j, iRow = 9, iCol = 11, iArr[iRow][iCol];

    printf("C2501\n");
    printf("3430302/x000x\n");
    printf("Safonov A.S.\n");
    printf("09.03.2020\n");
    printf("\n");

    for (i = 0; i < iRow; i++)
        for (j = 0; j < iCol; j++) iArr[i][j] = 100*i + 10*j + 1;

    prnIntArr(iRow, iCol, iArr);
    ChangeArr(&iRow, &iCol, &iArr[0][0]);
    prnIntArr(iRow, iCol, iArr);

    return 0;
}

void prnIntArr(int iRow, int iCol, int iArr[iRow][iCol])
{
    int i, j;

    printf("\nRow = %i  Col = %i\n",iRow, iCol);
    for (i = 0; i < iRow; printf("\n"), i++)
        for (j = 0; j < iCol; j++) printf("%6i ", iArr[i][j]);
}

void ChangeArr(int* piRow, int* piCol, int *piArr)
{
    int i, j, k, iLeft = 1, iPrime = 1;

    for (i = 0; i < *piRow; i++)
        for (j = 0; j < *piCol; j++)
        {
           for(k = 2; k < (*(piArr+*piCol*i+j)+1)/2; k++)
           {
               if (*(piArr + *piCol*i + j) % k == 0)
               {
                   *(piArr + *piCol*i + j) = iLeft;
                   iPrime = 0;
                   break;
               }
           }
	   if (iPrime == 1) iLeft = *(piArr+*piCol*i+j);
           iPrime = 1;
        }
}
