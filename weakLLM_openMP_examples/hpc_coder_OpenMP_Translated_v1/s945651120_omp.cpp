#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int x =0;
    int y =0;

    #pragma omp parallel for
    for (x=1;x<=9;x++)
    {
        for (y=1;y<=9;y++)
        cout << x << "x" << y << "=" << x*y << endl;
    }

    return 0;
}