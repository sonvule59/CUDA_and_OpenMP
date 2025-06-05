__global__ void kernel(int i, int j) {
  int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
  int local_i = thread_id * blockDim.x + threadIdx.y;
  int local_j = thread_id * blockDim.x + threadIdx.z;

  // Accessing elements of matrix A
  int a[3][3] = {{i, j, 0}, {i+1, j, 0}, {i, j+1, 0}};
  
  // Transposing matrix A
  int temp[3][3] = a;
  for (int k = 0; k < 3; k++) {
    for (int l = 0; l < 3; l++) {
      temp[k][l] = temp[l][k];
    }
  }

  // Adding element at local_i and j
  int sum = temp[thread_id][thread_id] + temp[thread_id+1][thread_id+1] + temp[thread_id][thread_id+2];

  // Store result in global variable
  int result = sum;
}

int main() {
  int gridDimX = 512;
  int blockDimY = 512;
  int gridSizeZ = 64;

  // Creating grid of threads
  dim3 threadsGrid(gridDimX, blockDimY, gridSizeZ);
  dim3 blockThreads(threadsGrid.x, threadsGrid.y, threadsGrid.z);

  // Launch kernel on each thread
  for (int i = 0; i < blockDimY; i++) {
    for (int j = 0; j < blockDimX; j++) {
      kernel<<<blockThreads>>>(i, j);
    }
  }

  // Collect results from all threads
  int globalSum = 0;
  for (int i = 0; i < blockDimY; i++) {
    for (int j = 0; j < blockDimX; j++) {
      globalSum += kernel[i][j];
    }
  }

  // Print final result
  cout << "Global Sum: " << globalSum << endl;

  return 0;
}