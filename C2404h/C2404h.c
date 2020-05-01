//C2404h
//3430302/90003
//Biga V.S.
//15.04.20
//
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
int main()
{
    printf("%s \n","C2404h");
    printf("%s \n","3430302/90003");
    printf("%s \n","Biga V.S.");
    printf("%s \n\n","15.04.20");

	int i, fl=1, length=0, fl_space, quantity=0;
	char tmp, *first_frase = (char*) malloc(0);
	FILE* inf = fopen("input2404h.txt","rt");
	FILE* outputf = fopen("output2404h.txt","wt+");
	if ( (inf == NULL) or (outputf == NULL) ) {
		printf("%s","ERROR. Input file not found or output file cannot generate.");
		return -1;
	}

	for( ; ; )//while ( !feof(inf) )
	{
		fscanf(inf, "%c", &tmp);
		if (   (tmp ==' ') or (tmp=='\t') or (tmp == '\n')   )  fl_space = 1;
		else fl_space = 0;

		if (  (fl_space==1) and (fl==1) ) continue;
		else if ( (tmp=='\0') or ( (fl_space==1) and (fl==0) ) ) break;
		else
		{
			length = length + 1;
			first_frase = (char*) realloc (first_frase, sizeof(char)*(length) );
			first_frase[length - 1] = tmp;
			fl = 0;
			continue;
		}
        }

    if ( length!=0 ) quantity = 1;
    else
    {
        printf("%s \n","Input text file does not contain frases.");
        return 0;
    }
	while ( !feof(inf) )
	{
	    fscanf(inf, "%c", &tmp);
   		if (   (tmp ==' ') or (tmp=='\t') or (tmp == '\n')   )  continue;

        for(i=0, fl=0; i<length; fl=1, i++)
            {
                if (tmp!=first_frase[i])
                    {
                        fl=0;
                        break;
                    }
            }

        if (fl=1)
        {
            if ( feof(inf) ) { quantity = quantity + 1; break; }
            fscanf(inf, "%c", &tmp);
        	if (   (tmp ==' ') or (tmp=='\t') or (tmp == '\n')  )  quantity = quantity + 1;
        }

	}
	for(i=0; i<32; i++)  fprintf(outputf, "%c", '-');
    fprintf(outputf, "\n %s %i", "Number of meetings of first frase in input file \"input2404h.txt\" : ", quantity);
	printf("%s %i\n","Number of meetings of first frase in input file \"input2404h.txt\" : ", quantity);
	return 0 ;
}
