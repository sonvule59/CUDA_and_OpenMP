__global__ void maxAreaKernel(float* A, int rows, int cols)
{
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    int col = blockIdx.y * blockDim.y + threadIdx.y;

    if(row >= rows && col >= cols)
    {
        float area = A[row * cols];
        
        // Check if the maximum value is within the grid boundaries
        if(area > 0)
        {
            // Update the maximum value on the GPU
            A[row * cols] = max(A[row * cols], area);

            // Print the updated value
            printf("Max Area at (%dx%d): %f\n", row, col, area);
        }
    }
}