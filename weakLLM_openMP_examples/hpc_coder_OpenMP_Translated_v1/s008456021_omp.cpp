#include<iostream>
#include<omp.h>
using namespace std;

int main(){
  int i,j;

  #pragma omp parallel for
  for(i=1;i<=9;i++){
    for(j=1;j<=9;j++){
      cout << i << 'x' << j << '=' << i*j << '\n';
    }
  }

}