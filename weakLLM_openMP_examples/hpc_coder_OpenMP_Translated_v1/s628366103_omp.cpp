#include<iostream>
#include<omp.h>
using namespace std;

#define QQ_LIMIT 9

int main(void){

  #pragma omp parallel for
  for(int i = 1 ;i <= QQ_LIMIT ;i++){
    for(int j = 1 ;j <= QQ_LIMIT ;j++ ){
      cout << i << "x" << j << "=" << i*j << endl;
    }
  }

  return 0;
}