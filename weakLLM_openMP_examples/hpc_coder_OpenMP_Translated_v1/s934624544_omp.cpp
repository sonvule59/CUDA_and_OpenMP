#include<iostream>
#include<omp.h>
#define MAX 9
using namespace std;
int main(){
  int i = 1, j = 1;
  int sum;
  #pragma omp parallel for private(i,j,sum)
  for( i = 1 ; i <= MAX ; i++ ){
    for(j = 1 ; j <= MAX ; j++ ){
      sum = i * j;
      cout << i << "x" << j << "=" << sum << endl;
    }
  }
  return 0;
}