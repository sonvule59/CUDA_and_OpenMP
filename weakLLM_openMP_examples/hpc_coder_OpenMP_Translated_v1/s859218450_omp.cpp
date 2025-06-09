#include<iostream>
#include<omp.h>
#define B 9
using namespace std;
int main(){
  #pragma omp parallel for
  for(int i=0;i<B*B;cout<<(i/B+1)<<'x'<<(i%B+1)<<'='<<(i/B+1)*(i%B+1)<<endl,i++){}
  return 0;
}