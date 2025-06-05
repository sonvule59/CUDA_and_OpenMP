#include <cuda_runtime.h>
#include <cuda_runtime_api.h>

__global__ void kernel(int x, int y) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;

    // Calculate product of x and y on GPU
    float product = x * y;

    // Store product in local memory
    cudaMemsetAsync(&product, 0, sizeof(float), cudaMemcpyHostToDevice);

    // Update global variables
    x = x + 1;
    y = y + 1;

    // Execute kernel on CPU
    kernel<<<gridDim.x, blockDim.y>>>(i, j);
    
    // Update global variables again
    x = x - 1;
    y = y - 1;

    // Copy local memory back to host
    cudaMemcpy(host_ptr, &product, sizeof(float), cudaMemcpyDeviceToHost);

    // Release device memory
    cudaMemsetAsync(&product, 0, sizeof(float), cudaMemcpyDeviceToHost);
}

int main(int argc, const char * argv[]) {
    // Initialize CUDA runtime
    cudaInit();

    // Create grid with dimensions (9x9)
    dim3 gridDim(9, 9);
    dim3 blockDim(gridDim.x, blockDim.y);

    // Allocate shared memory for product variable
    cudaMallocSync(&shared_ptr, sizeof(float) * 9 * 9);

    // Set block size to (1x1)
    blockDim.set(1, 1);

    // Create kernel function
    kernel<<<gridDim.x, blockDim.y>>>(0, 0);

    // Launch kernel on GPU
    cudaLaunchKernel(kernel, gridDim.x, gridDim.y, 0, shared_ptr);

    // Wait for kernel to finish executing
    cudaWaitAll();

    // Clean up CUDA resources
    cudaFreeSync(shared_ptr);
    cudaFreeMemSync(shared_ptr);

    // Print result
    cout << "Product of x and y on GPU: " << static_cast<float>(shared_ptr[0]) << endl;

    return 0;
}