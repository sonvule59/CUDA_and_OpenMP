#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int a = 1, b = 1;
    #pragma omp parallel for
    for(int a = 1; a <= 9; a++){
        for(int b = 1; b <= 9; b++){
            cout << a << "x" << b << "=" << a*b << endl;
        }
    }
    return 0;
}