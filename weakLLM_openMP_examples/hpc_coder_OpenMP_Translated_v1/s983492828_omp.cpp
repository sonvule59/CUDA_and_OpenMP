#include<iostream>
#include<omp.h>
using namespace std;
int i;
int I;
int main(){
     #pragma omp parallel for
     for(i=1;i<10;i++){
        for(I=1;I<10;I++){
          cout<<i<<'x'<<I<<'='<<i*I<<'\n';
         }
      }
    return 0;
}