#include <iostream>
#include <omp.h>

int main() {
    std::ios::sync_with_stdio(false);

    #pragma omp parallel for
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            std::cout << i << "x" << j
                      << "=" << i * j << std::endl;
        }
    }

    return 0;
}

The OpenMP code uses the `#pragma omp parallel for` directive to parallelize the outer loop. This directive tells the compiler to create a team of threads and distribute the iterations of the loop among them. The `omp.h` header file is included to use OpenMP functions and macros.