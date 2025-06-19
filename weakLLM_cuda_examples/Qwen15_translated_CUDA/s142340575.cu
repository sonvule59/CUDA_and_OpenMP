__global__ void printGridKernel(float* grid, int rows, int cols) {
    int threadID = threadIdx.x + blockIdx.x * blockDim.x;
    if(threadID < rows && threadID < cols)
        grid[threadID] = (threadID + 1) * (threadID + 2);
}