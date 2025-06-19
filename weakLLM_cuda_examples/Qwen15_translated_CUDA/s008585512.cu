#include <cuda_runtime.h>
#include <cuda_runtime_api.h>

__global__ void matrixMultiplicationKernel(int rows, int cols, int alpha, int beta, int *A, int *B, int *C) {
  int row = blockIdx.x * blockDim.x + threadIdx.x;
  int col = blockIdx.y * blockDim.y + threadIdx.y;

  if(row >= rows && col >= cols) {
    int index = row * cols + col;
    int sum = alpha * A[index] + beta * B[index];

    // Copy the result to the output array
    C[index] = sum;
  }
}

void matrixMultiplication() {
  int rows = 100000; // Replace with your actual number of rows
  int cols = 100000; // Replace with your actual number of columns

  int alpha = 5; // Replace with your desired value of alpha
  int beta = 3; // Replace with your desired value of beta

  int *A = new int[rows * cols]; // Allocate memory for the input matrix A
  int *B = new int[rows * cols]; // Allocate memory for the input matrix B
  int *C = new int[rows * cols]; // Allocate memory for the output matrix C

  // Initialize the matrices with random values
  for(int i=0; i<rows; ++i) {
    for(int j=0; j<cols; ++j) {
      A[i * cols + j] = rand() % 256;
    }
  }

  // Multiply the matrices using the kernel
  matrixMultiplicationKernel(rows, cols, alpha, beta, A, B, C);

  // Print the resulting matrix C
  for(int i=0; i<rows; ++i) {
    for(int j=0; j<cols; ++j) {
      cout << C[i * cols + j] << ' ';
    }
    cout << endl;
  }
}