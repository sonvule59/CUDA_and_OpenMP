#include <stdio.h>
#include <omp.h>

int main(){
  int answer;
  #pragma omp parallel for
  for(int i=1; i<=9; i++){
    for(int a=1; a<=9; a++){
      answer = i*a;
      printf("%dx%d=%d\n", i,a,answer);
    }
  }	
  return 0;
}