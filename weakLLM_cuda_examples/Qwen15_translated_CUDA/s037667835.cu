__global__ void kernel(int x, int y) {
    int sum = 0;
    
    // Accessing elements of matrix A on GPU
    for (int i = blockIdx.x * blockDim.x + threadIdx.x; i < blockDim.x * gridDim.x; i += blockDim.x * blockDim.y) {
        sum += x * y;
    }

    // Updating global variable 'sum'
    gl_FragColor[0] = sum / blockDim.x * 255.0;
}