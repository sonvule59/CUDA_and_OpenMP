#include <stdio.h>

__global__ void kernel(int *x, int *y) {
int idx = threadIdx.x + blockIdx.x * blockDim.x;
if (idx < 100) {
x[idx] = idx;
y[idx] = idx;
}
}

int main() {
int *x, *y;
int size = 100;
x = (int *)malloc(size * sizeof(int));
y = (int *)malloc(size * sizeof(int));

kernel<<<1, size>>>(x, y);

for (int i = 0; i < size; i++) {
printf("%d x %d = %d\n", x[i], y[i], x[i] * y[i]);
}

free(x);
free(y);
return 0;
}