#include <iostream>
#include <omp.h>

static const int MaxNum = 9;
static void print_qq()
{
    #pragma omp parallel for
    for (int i = 1; i <= MaxNum; ++i) {
        for (int j = 1; j <= MaxNum; ++j) {
            std::cout << i << "x" << j << "=" << i * j << std::endl;
        }
    }
}

int main()
{
    print_qq();
}

The OpenMP version uses the `#pragma omp parallel for` directive to parallelize the outer loop. This directive tells the compiler to create a team of threads and distribute the iterations of the loop among them. The `omp.h` header file is used to include the OpenMP library.