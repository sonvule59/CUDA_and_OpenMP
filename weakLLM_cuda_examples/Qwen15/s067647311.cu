#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <cuda_runtime_gemm.h>

__global__ void exprKernel(int x, int y) {
    // CUDA kernel implementation
    int threadIdx = threadIdx.x;
    int blockIdx = blockIdx.x;
    
    if(threadIdx<9 && blockIdx<9){
        // Calculate product of x and y on a grid of size 9x9
        int product = x*x + y*y;
        
        // Store the result in a global variable
        string result = expr(product, product);
        
        // Write the result to a file
        ofstream out("result.txt");
        out << result << endl;
    }
}

int main() {
    cudaSetDevice(0); // Set device to GPU
    cudaMalloc(&deviceMemory, sizeof(string)); // Allocate memory for result variable
    
    // Global variables declaration
    string resultVariable = "";
    
    // Loop over all elements in the set
    for(auto it = c.begin(); it != c.end(); ++it) {
        // Copy element to device memory
        cudaMemcpy(deviceMemory, *it, sizeof(string), cudaMemcpyHostToDevice);
        
        // Call kernel function
        exprKernel<<<1, 1>>>(deviceMemory, deviceMemory);
        
        // Copy result back to host memory
        cudaMemcpy(resultVariable, deviceMemory, sizeof(string), cudaMemcpyDeviceToHost);
        
        // Free device memory
        cudaFree(deviceMemory);
    }
    
    // Print result variable
    cout << resultVariable << endl;
    
    // Release device resources
    cudaFreeDevice();
    
    return 0;
}