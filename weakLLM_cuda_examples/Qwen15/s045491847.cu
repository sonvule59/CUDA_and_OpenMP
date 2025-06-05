__global__ void kernel(int a, int b) {
    int n = blockDim.x * gridDim.x;
    int i = threadIdx.x + blockIdx.x * n;
    int j = threadIdx.y + blockIdx.y * n;

    if (i < 1 || i > 9 || j < 1 || j > 9)
        return;

    int temp = a * b;
    a = temp / b;
    b = temp % b;

    __syncthreads();

    if (j < 1 || j > 9)
        return;

    a += a * j;
    b += b * j;

    __syncthreads();

    if (i < 2 || i > 8)
        return;

    a /= 2;
    b /= 2;

    __syncthreads();

    if (j < 2 || j > 7)
        return;

    a += a * j;
    b += b * j;

    __syncthreads();
}

int main() {
    int a = 1, b = 1, i, n;

    for (i = 1; i <= 9; i++) {
        for (n = 1; n <= 9; n++) {
            kernel<<<grid_size, block_size>>>(a, b);
            // Print the result on the GPU
            std::cout << "a = " << a << ", b = " << b << std::endl;
            b = n + 1;
        }
        a = i + 1;
        b = 1;
    }

    return 0;
}