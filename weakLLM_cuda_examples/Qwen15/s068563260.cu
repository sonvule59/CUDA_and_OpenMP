__global__ void mult_matrix_kernel(int a, int b, int c) {
    int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
    if(thread_id < a && thread_id < b && thread_id < c)
        c = a*b;
    
    // Write the result to device memory
    __shared__ int shared_result[3];
    shared_result[thread_id] = c;
    
    // Update global variables
    a += blockDim.x * gridDim.x;
    b += blockDim.x * gridDim.x;
}