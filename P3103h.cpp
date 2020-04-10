#include <iostream>
unsigned long long int Ackherman_func(int m, int n);
unsigned long long int call_counter=0;

int main()
{
    int m,n;
    std::cout << "Enter options for Ackerman function \n"; // m <= 3 n <= 4
    std::cin >> m >> n;
    if ( (m < 0)||(n < 0) )
    {
        std::cout << "ERROR. Unacceptable condition. \n";
        return -1;
    }
    unsigned long long int Result = Ackherman_func(m,n);
    //printf("%s llu \n" "Result = ", Result);
    std::cout << "Result = " << (unsigned long long int) Result << std::endl << "Function was called : " << call_counter << std::endl;

    return 0;
}
unsigned long long int Ackherman_func(int m, int n)
{
    //static int counter = 0;
    unsigned long long int Result;
    if (m==0) Result = n + 1;
    else if(n==0) Result = Ackherman_func( m-1, 1 );
    else Result = Ackherman_func( m-1, Ackherman_func( m, n-1 )  );
    //counter = counter + 1;
    call_counter = call_counter +1 ;
    return Result;
}
