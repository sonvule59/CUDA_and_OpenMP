#include<iostream>
#include<omp.h>
int main(){
  int i,j;
  #pragma omp parallel for private(i,j)
  for(i=1;i<10;i++)for(j=1;j<10;j++)std::cout<<i<<'x'<<j<<'='<<i*j<<std::endl;
  return 0;
}