__global__ void printMatrix(int rows, int cols, int value) {
    int threadID = threadIdx.x + blockIdx.x * blockDim.x;
    if(threadID < rows && threadID < cols) {
        // Print element at current grid location
        printf(" %dx%d=%d\n", threadID, row, col, value);
    }
}