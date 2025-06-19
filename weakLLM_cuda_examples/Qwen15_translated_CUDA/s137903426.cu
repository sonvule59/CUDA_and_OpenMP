c++
__global__ void addXZ(int *x, int *z) {
    int idx = threadIdx.x + blockDim.x * blockIdx.x;
    int sum = 0;
    for (int i = 0; i < blockDim.x * gridDim.x; i += blockDim.x) {
        sum += x[idx] * z[idx];
    }
    // Store result in local memory
    *z = sum;
}

int main() {
    int x = 0, y = 0, z = 0;
    dim3 block_size(16, 16, 1); // 16x16x1 thread block size
    dim3 grid_size(16, 16, 1); // 16x16x1 grid size

    addXZ<<<grid_size, block_size>>>(x, &z);

    while (true) {
        x += 1;
        while (true) {
            z += 1;
            y = x * z;
            printf("%d %d=%d\n", x, z, y);
            if (z >= 9) {
                break;
            }
        }
        z = 0;
        if (x >= 9) {
            break;
        }
    }

    return 0;
}
 c++
__global__ void addXZ(int *x, int *z) {
    int idx = threadIdx.x + blockDim.x * blockIdx.x;
    int sum = 0;
    for (int i = 0; i < blockDim.x * gridDim.x; i += blockDim.x) {
        sum += x[idx] * z[idx];
    }
    // Store result in global memory
    *z = sum;
}

int main() {
    int x = 0, y = 0, z = 0;
    dim3 block_size(16, 16, 1); // 16x16x1 thread block size
    dim3 grid_size(16, 16, 1); // 16x16x1 grid size

    addXZ<<<grid_size, block_size>>>(x, &z);

    while (true) {
        x += 1;
        while (true) {
            z += 1;
            y = x * z;
            printf("%d %d=%d\n", x, z, y);
            if (z >=