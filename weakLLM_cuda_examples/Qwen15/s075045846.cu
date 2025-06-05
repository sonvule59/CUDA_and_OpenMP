__global__ void print_matrix(int matrix[2][2], int minNum, int maxNum) {
  // Get thread ID
  int threadIdx = blockIdx.x * blockDim.x + threadIdx.y;

  // Check if thread index is within range
  if (threadIdx < minNum || threadIdx > maxNum) {
    return;
  }

  // Access element at row and column indices
  int row = threadIdx.x;
  int col = threadIdx.y;

  // Calculate product of row and column elements
  int product = matrix[row][col];

  // Print element on screen
  std::cout << product << " ";
}