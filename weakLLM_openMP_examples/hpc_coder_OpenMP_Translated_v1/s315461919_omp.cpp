#include <iostream>
#include <omp.h>

const int N = 9;

int main(void) {
  #pragma omp parallel for
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cout << i << "x" << j << "=" << i * j << std::endl;
    }
  }
   
  return 0;
}

The OpenMP version uses the `#pragma omp parallel for` directive to parallelize the outer loop. This directive tells the compiler to create a team of threads and distribute the iterations of the loop among them. The inner loop is not parallelized, as it is not necessary to parallelize it.