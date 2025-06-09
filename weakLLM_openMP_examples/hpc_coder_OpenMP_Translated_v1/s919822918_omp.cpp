#include<iostream>
#include<omp.h>

using namespace std;

int main(){

  int a=1;
  int b=1;

  #pragma omp parallel for
  for(a=1;a<10;a++){
  
    #pragma omp parallel for
    for(b=1;b<10;b++){

      cout << a <<"x"<<b<<"="<<a*b << endl;
    }
  }
  
  return 0;
}