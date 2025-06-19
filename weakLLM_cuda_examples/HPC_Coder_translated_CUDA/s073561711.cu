#include<stdio.h>

__global__ void multiply(int *a, int *b, int *c) {
    int i = threadIdx.x;
    c[i] = a[i] * b[i];
}

int main() {
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int c[9];

    multiply<<<1, 9>>>(a, b, c);

    for (int i = 0; i < 9; i++) {
        printf("%d x %d = %d\n", a[i], b[i], c[i]);
    }

    return 0;
}