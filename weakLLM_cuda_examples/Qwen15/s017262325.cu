__global__ void printMatrix(int i, int j, int value) {
    int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
    if(thread_id < 1 || thread_id > 9)
        return;

    // Check if the row and column indices are within the range of the matrix
    if(thread_id >= i && thread_id <= i*9 && thread_id < j && thread_id <= j*9)
        value[thread_id] = value[thread_id] * value[thread_id];
}