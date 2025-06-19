__global__ void printGrid(int rows, int cols, int value) {
  // Global variables
  int thread_id = blockIdx.x * blockDim.x + threadIdx.x;
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  int col = blockIdx.z * blockDim.z + threadIdx.z;

  // Check if the grid is out of bounds
  if (row >= rows || col >= cols || row < 0 || col < 0) {
    return;
  }

  // Calculate the value at the current grid location
  int grid_value = value * row * col;

  // Print the value on the grid
  printf(" %dx%d=%d\n", row, col, grid_value);
}

int main() {
  // Define grid dimensions
  int rows = 10;
  int cols = 10;
  int value = 5;

  // Create a CUDA grid
  dim3 threads_per_block(rows / blockDim.x, cols / blockDim.y, 1);
  dim3 grid_size((rows + threads_per_block.x - 1) / threads_per_block.x,
                 (cols + threads_per_block.y - 1) / threads_per_block.y);

  // Allocate memory for the grid
  int grid[rows][cols];
  
  // Copy the grid values from C++ to CUDA
  cudaMemcpy(grid, &value, sizeof(int), cudaMemcpyHostToDevice);

  // Launch the kernel
  printGrid<<<grid_size,threads_per_block>>>(rows, cols, grid[0]);

  // Read the grid values back from CUDA
  int grid_values[rows][cols];
  cudaMemcpy(grid_values, grid, sizeof(int), cudaMemcpyDeviceToHost);

  // Display the grid values
  FOR(i,0,rows) {
    FOR(j,0,cols) {
      printf("%dx%d=%d\n", i, j, grid_values[i][j]);
    }
  }

  return 0;
}