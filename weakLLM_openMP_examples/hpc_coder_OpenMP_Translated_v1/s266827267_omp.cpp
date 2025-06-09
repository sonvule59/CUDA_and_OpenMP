#include <cstdio>
#include <omp.h>

int main() {
  int i, j;
#pragma omp parallel for private(i, j)
  for (i = 0; i < 9; ++i) {
    for (j = 0; j < 9; ++j) {
      std::printf("%dx%d=%d\n", i + 1, j + 1, (i + 1) * (j + 1));
    }
  }

  return 0;
}

The OpenMP code uses the `#pragma omp parallel for` directive to parallelize the outer loop. The `private(i, j)` clause ensures that each thread has its own copy of the loop variables `i` and `j`.