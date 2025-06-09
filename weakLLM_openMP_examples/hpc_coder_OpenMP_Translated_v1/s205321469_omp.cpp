#include <iostream>
#include <omp.h>

auto main() -> int {
    #pragma omp parallel for collapse(2)
    for (int x = 1; x <= 9; x++) {
        for (int y = 1; y <= 9; y++) {
            std::cout << x << "x" << y << "=" << (x*y) << std::endl;
        }
    }
    return 0;
}

The `#pragma omp parallel for collapse(2)` directive tells OpenMP to parallelize the two nested loops. The `collapse(2)` clause tells OpenMP to collapse the two loops into one, which can improve performance.