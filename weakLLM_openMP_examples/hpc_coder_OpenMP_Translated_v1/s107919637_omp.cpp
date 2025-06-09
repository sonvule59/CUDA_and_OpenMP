#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
    int a;
    #pragma omp parallel for
    for(int i=1;i<10;i++){
    for(int j=1;j<10;j++){
    a=i*j;
    cout<<i<<'x'<<j<<'='<<a<<'\n';
    }
    }
    return 0;
}