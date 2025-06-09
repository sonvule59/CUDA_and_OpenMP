#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    #pragma omp parallel for
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cout<<i<<'x'<<j<<'='<<i*j<<'\n';
        }
    }
    return 0;
}