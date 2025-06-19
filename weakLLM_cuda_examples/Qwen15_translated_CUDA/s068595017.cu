__global__ void printGridKernel(float* grid, int rows, int cols) {
    int threadID = threadIdx.x + blockIdx.x * blockDim.x;
    if(threadID < rows && threadID < cols) {
        float x = grid[threadID];
        float y = grid[threadID+1];
        float z = grid[threadID+2];

        // Print the grid at this point
        printf("x = %f, y = %f, z = %f\n", x, y, z);
    }
}

int main() {
    float grid[9][9] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 0, 1}, {2, 3, 4}, {5, 6, 7}};
    int rows = sizeof(grid) / sizeof(grid[0]);
    int cols = sizeof(grid[0]) / sizeof(grid[0][0]);

    __shared__ float sharedGrid[row * cols];

    printGridKernel<<<grid_size, block_size>>>(sharedGrid, rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%f ", sharedGrid[i * cols + j]);
        }
        printf("\n");
    }

    return 0;
}