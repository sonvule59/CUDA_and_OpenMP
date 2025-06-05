__global__ void matrix_multiplication_kernel(int rows, int cols, int* A, int* B, int* C) {
  int row = blockIdx.x * blockDim.x + threadIdx.x;
  int col = blockIdx.y * blockDim.y + threadIdx.y;

  if (row >= rows && col >= cols) {
    int sum = 0;
    
    // Add elements of A and B column-wise
    for (int i = 0; i < cols; ++i) {
      sum += A[row * cols + i] * B[col * cols + i];
    }

    // Store result in C
    C[row * cols + col] = sum;
  }
}