__global__ void printMatrix(int matrix[9][9], int a, int b)
{
    int threadID = threadIdx.x + blockIdx.x * blockDim.x;
    if(threadID < 9){
        int row = threadIdx.y + blockIdx.y * blockDim.y;
        int col = threadIdx.z + blockIdx.z * blockDim.z;

        // Check if the element is within range
        if(a <= row && row < 9 && b <= col && col < 9){
            printf("%dx%d=%d\n", matrix[row][col], matrix[a][b], matrix[a * b]);
        }
    }
}