#include <cuda_runtime.h>

__global__ void kernel_function(int a, int b) {
    int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
    
    if(thread_id < 1 || thread_id >= 10)
        return;

    int temp = (thread_id - 1) * blockDim.x + threadIdx.x;
    int other_thread_id = thread_id - blockDim.x;
    
    // Calculate product of a and b on other thread
    int product = a * b;
    
    // Store product in local memory
    int local_product = temp * product;
    
    // Write product to device memory
    cudaMemcpy(&local_product, &product, sizeof(int), cudaMemcpyDeviceToHost);
    
    // Update a and b variables on this thread
    a = a + blockDim.x * gridDim.x;
    b = b + blockDim.x * gridDim.x;
}

int main() {
    int a = 1, b = 2;
    
    // Launch kernel function on GPU
    kernel_function<<<1, 1>>>(a, b);

    // Read result from device memory
    int result = cudaGetDeviceLocalMemSize(0, &local_product);
    
    cout << "Result: " << result << endl;

    return 0;
}