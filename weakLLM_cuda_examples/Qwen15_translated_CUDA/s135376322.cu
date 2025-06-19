#include <cuda_runtime.h>
#include <cuda_runtime_api.h>

__global__ void kernel(int a, int b, int kake) {
    int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
    if(thread_id < 1 || thread_id >= 10) return;

    int x = threadIdx.x;
    int y = threadIdx.y;
    int z = threadIdx.z;

    // Calculate the product of x and y for each element in the array
    int product_x = x * y;
    int product_y = x * z;
    int product_z = y * z;

    // Store the product in the kake variable
    kake += product_x * product_y * product_z;
}

int main() {
    int a = 0;
    int b = 0;
    int kake;

    // Allocate memory on the GPU
    cudaMalloc(&a, sizeof(int));
    cudaMalloc(&b, sizeof(int));
    cudaMalloc(&kake, sizeof(int));

    // Set up the kernel function
    kernel<<<gridDim[0], blockDim[1]>>>(a, b, kake);

    // Launch the kernel on all threads
    cudaMemcpy(kake, &a, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(kake, &b, sizeof(int), cudaMemcpyHostToDevice);
    kernel<<<gridDim[0], blockDim[1]>>>(a, b, kake);

    // Read the result from the GPU
    int result = cudaMemcpy(kake, &b, sizeof(int), cudaMemcpyDeviceToHost);

    // Print the result
    cout << "Result: " << result << endl;

    // Free the memory allocated on the GPU
    cudaFree(a);
    cudaFree(b);
    cudaFree(kake);

    return 0;
}