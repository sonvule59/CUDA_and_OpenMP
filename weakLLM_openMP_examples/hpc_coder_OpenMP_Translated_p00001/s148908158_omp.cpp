#include<iostream>
#include<algorithm>
#include<omp.h>
using namespace std;

int main()
{
    int a[10];
    for(int i=0;i<10;i++)
        cin>>a[i];
    sort(a,a+10);
    #pragma omp parallel for
    for(int j=0;j<3;j++){
        cout<<a[9-j]<<endl;
    }
    return 0;
    
}