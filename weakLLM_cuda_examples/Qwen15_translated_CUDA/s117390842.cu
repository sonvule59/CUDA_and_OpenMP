__global__ void add(int* a, int* b, int* c, int n) {
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (index >= n) return;
    
    c[index] = a[index] + b[index];
    
    // Add padding to ensure correct size of output array
    c[index] += n - index;
    
    // Update global variables
    blockDim.x /= n;
    gridDim.x = n;
    
    // Compute sum of elements in each block
    int sum = 0;
    FOR(block, 0, blockDim.x, blockDim.y) {
        sum += c[block];
    }
    
    // Copy result to output array
    cudaMemcpy(c, &sum, sizeof(int), cudaMemcpyHostToDevice);
}

int main() {
    int n = 9;
    int a[n], b[n], c[n];
    
    // Allocate memory on device
    add<<<gridDim, blockDim>>>(a, b, c, n).transferToHost();
    
    // Print results
    FOR(i, 0, n, blockDim.x) {
        FOR(j, 0, n, blockDim.y) {
            cout << i + 1 << "x" << j + 1 << "=" << a[i] + b[j] << "\n";
        }
    }
    
    // Release memory on device
    cudaDeviceSynchronize();
    
    return 0;
}