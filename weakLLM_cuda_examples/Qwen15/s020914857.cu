c
#include <cuda_runtime.h>

__global__ void kernel(int m, int n)
{
  int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
  int row = threadIdx.y + blockIdx.y * blockDim.y;
  int col = threadIdx.z + blockIdx.z * blockDim.z;

  // Accessing elements of matrix using grid indices
  int element = (row * m * n) + (col * m);

  // Adding element to local matrix
  int local_matrix[row * m * n] = element + 1;

  // Updating global matrix
  for(int i = 0; i < m; ++i)
  {
    for(int j = 0; j < n; ++j)
    {
      global_matrix[i * n + j] = local_matrix[i * n + j];
    }
  }

  // Updating global matrix by multiplying it with a constant value
  global_matrix[0] *= 2;
}

int main()
{
  int m = 1;
  int n = 1;

  while (true)
  {
    if (n == 10)
    {
      m = m + 1;
      n = 1;
    }
    if (m == 10) break;

    // Launch kernel on GPU
    cudaMalloc(&local_matrix, sizeof(int) * (m * n));
    cudaMemcpy(local_matrix, &global_matrix[0], sizeof(int) * (m * n), cudaMemcpyHostToDevice);
    kernel<<<gridDim, blockDim>>>(m, n);

    // Wait for all threads to finish execution
    cudaDeviceWaitIdle();

    // Accessing elements of matrix using grid indices
    int element = (threadIdx.x + blockIdx.x * blockDim.x) * blockDim.x + threadIdx.y + blockIdx.y * blockDim.y;
    int local_matrix_row = threadIdx.y + blockIdx.y * blockDim.y;
    int local_matrix_col = threadIdx.z + blockIdx.z * blockDim.z;

    // Adding element to local matrix
    int local_matrix[row * m * n] = element + 1;

    // Updating global matrix
    for(int i = 0; i < m; ++i)
    {
      for(int j = 0; j < n; ++j)
      {
        global_matrix[i * n + j] = local_matrix[i * n + j];
      }
    }

    // Updating global matrix by multiplying it with a constant value
    global_matrix[0] *=