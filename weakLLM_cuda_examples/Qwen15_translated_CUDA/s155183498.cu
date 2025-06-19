__global__ void kernel(int x, int y) {
    int sum = 0;
    
    for (int i = blockIdx.x * blockDim.x + threadIdx.x; i < blockDim.x * gridDim.x; i += blockDim.x * blockDim.y) {
        sum += x * y;
    }
    
    // Store result in device memory
    int z = sum;
    
    // Update global variable
    global_x += blockDim.x * gridDim.x;
    global_y += blockDim.y * gridDim.x;
    
    // Write result back to host memory
    cudaMemcpy(host_x, &z, sizeof(z), cudaMemcpyDeviceToHost);
}

int main() {
    dim3 threads_per_block(3, 3, 3); // 3 threads per block, 3 blocks in grid
    dim3 grid_size(9, 9, 9); // 9x9x9 grid
    
    // Allocate device memory
    int* host_x = new int[grid_size.x * grid_size.y * blockDim.x * blockDim.y];
    
    // Launch kernel on GPU
    kernel<<<threads_per_block, grid_size>>>(host_x, host_x + grid_size.x * grid_size.y * blockDim.x * blockDim.y);
    
    // Copy result back to host memory
    cudaMemcpy(host_x, host_x + grid_size.x * grid_size.y * blockDim.x * blockDim.y, sizeof(int), cudaMemcpyDeviceToHost);
    
    // Print results
    for (int i = 0; i < grid_size.x; i++) {
        for (int j = 0; j < grid_size.y; j++) {
            cout << host_x[i * grid_size.y + j] << " ";
        }
        cout << endl;
    }

    delete[] host_x;
    
    return 0;
}