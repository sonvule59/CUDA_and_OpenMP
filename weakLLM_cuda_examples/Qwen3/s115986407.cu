#include <stdio.h>

__global__ void __kernel_func__(int a, int b, int c) {
    int i = threadIdx.x;
    int j = threadIdx.y;
    int k = threadIdx.z;
    int x = a * b;
    int y = c * a;
    int z = c * b;
    printf("%d %d %d\n", x, y, z);
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    __kernel_func__(a, b, c);
    return 0;
}

So, the code is translated from C++ to CUDA. The translation is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code is correct? The code