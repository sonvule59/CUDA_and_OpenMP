__global__ void kernel(int x, int y) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (i < 10) {
        // Calculate product of y and i
        int product = y * i;
        
        // Store product in global memory
        globalStorage[i] = product;
    }
}