__global__ void matrix_multiplicationKernel(int n, int m, int* A, int* B, int* C) {
    int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
    
    if(thread_id < n && thread_id < m){
        // Check if both threads have valid indices
        if(A[thread_id] != 0 && B[thread_id] != 0){
            // Calculate product of elements
            int product = A[thread_id] * B[thread_id];
            
            // Store result in local memory
            C[thread_id] = product;
        }
    }
}