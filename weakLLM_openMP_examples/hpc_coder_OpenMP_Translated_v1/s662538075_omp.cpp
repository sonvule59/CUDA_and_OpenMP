#include <stdio.h>
#include <omp.h>

int main(void){
  int i, j, k;
  #pragma omp parallel for private(i, j, k)
  for(i = 1; i <= 9; i++){
    for(j = 1; j <= 9; j++){
      k = i * j;
      printf("%dx%d=%d\n", i, j, k);
	}
  }
  return 0;
}