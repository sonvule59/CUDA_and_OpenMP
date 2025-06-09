#include <cstdio>
#include <omp.h>

int main() {
  int factors[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  #pragma omp parallel for
  for (int i = 0; i < sizeof(factors) / sizeof(factors[0]); i++) {
    for (int j = 0; j < sizeof(factors) / sizeof(factors[0]); j++) {
      std::printf("%dx%d=%d\n", factors[i], factors[j], factors[i] * factors[j]);
    }
  }
  return 0;
}

The OpenMP version uses the `#pragma omp parallel for` directive to parallelize the outer loop. The `for` loop inside the parallel region is executed in parallel by multiple threads. The `factors` array is shared among all threads, so there is no need to use `std::printf` with `#pragma omp critical`.