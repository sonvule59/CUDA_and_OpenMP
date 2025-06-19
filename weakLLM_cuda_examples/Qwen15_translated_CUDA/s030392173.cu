__global__ void printMatrix(int i, int j, int value)
{
    int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
    if(thread_id < 10)
    {
        // Access element at row and column index
        int row = i * blockDim.x + threadIdx.x;
        int col = j * blockDim.x + threadIdx.x;
        
        // Store element value in global variable
        global_matrix[row][col] = value;
    }
}