__global__ void printMatrix(int rows, int cols) {
    int threadID = threadIdx.x + blockIdx.x * blockDim.x;
    if(threadID < rows && threadID < cols) {
        printf("%d ", matrix[threadID]);
    }
}