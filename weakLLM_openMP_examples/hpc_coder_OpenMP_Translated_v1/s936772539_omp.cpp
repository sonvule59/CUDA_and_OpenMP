#include <iostream>
#include <omp.h>
using namespace std;
int main() {
  int a,b;
  #pragma omp parallel for
  for(int j=1;j<=9;j++){
  for(int i=1;i<=9;i++)
    cout<<j<<'x'<<i<<'='<<j*i<<endl;
  }  
}