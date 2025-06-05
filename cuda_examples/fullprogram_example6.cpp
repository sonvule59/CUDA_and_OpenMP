#include <iostream>
#include <cmath>
#include <omp.h>

void nowait_example2(int n, float *a, float *b, float *c, float *y, float *z) {
    int i;
    #pragma omp parallel
    {
        #pragma omp for schedule(static) nowait
        for (i = 0; i < n; i++) c[i] = (a[i] + b[i]) / 2.0f;
        
        #pragma omp for schedule(static) nowait
        for (i = 0; i < n; i++) z[i] = sqrtf(c[i]);
        
        #pragma omp for schedule(static) nowait
        for (i = 1; i <= n; i++) y[i] = z[i - 1] + a[i];
    }
}

int main() {
    const int n = 10;
    float a[n + 1], b[n + 1], c[n], y[n + 1], z[n];

    // Initialize input arrays
    for (int i = 0; i <= n; ++i) {
        a[i] = i * 1.0f;
        b[i] = (n - i) * 1.0f;
    }

    // Call the function
    nowait_example2(n, a, b, c, y, z);

    // Print results
    std::cout << "c: ";
    for (int i = 0; i < n; ++i) std::cout << c[i] << " ";
    std::cout << "\nz: ";
    for (int i = 0; i < n; ++i) std::cout << z[i] << " ";
    std::cout << "\ny: ";
    for (int i = 1; i <= n; ++i) std::cout << y[i] << " ";
    std::cout << std::endl;

    return 0;
}
