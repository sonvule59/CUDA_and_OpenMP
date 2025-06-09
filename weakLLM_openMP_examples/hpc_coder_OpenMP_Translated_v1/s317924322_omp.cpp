#include<iostream>
#include<omp.h>
using namespace std;

int main(){
     int m,n;
     #pragma omp parallel for private(m,n)
     for(m=1;m<10;m++){
       for(n=1;n<10;n++){
         cout << m << "x" << n << "=" << m*n << endl;
       }
     }

 return 0;
}