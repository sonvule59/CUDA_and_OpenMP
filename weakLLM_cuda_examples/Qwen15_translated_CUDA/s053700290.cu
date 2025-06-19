__global__ void matrixMultiplicationKernel(int n, int m, float* A, float* B) {
    int threadID = threadIdx.x + blockIdx.x * blockDim.x;
    if(threadID < n && threadID < m){
        float sum = 0.0f;
        
        // loop through each element of A and B
        for(int i = threadIdx.x; i < n; i += blockDim.x)
            for(int j = threadIdx.x; j < m; j += blockDim.x){
                sum += A[i] * B[j];
            }

        // store the result in a local variable
        float c = sum;
        
        // update the global variable with the result
        A[threadID] = c;
        B[threadID] = c;
    }
}