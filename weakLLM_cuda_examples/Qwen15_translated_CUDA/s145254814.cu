__global__ void kernel(int x, int y, int z)
{
    // Global variables
    int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
    int global_x = x + thread_id * blockDim.x;
    int global_y = y + thread_id * blockDim.x;

    // Local variables
    int local_x = global_x / blockDim.x;
    int local_y = global_y / blockDim.x;

    // Perform multiplication
    int result = local_x * local_y;

    // Store result in device memory
    __syncthreads();
    if(thread_id % 2 == 0) {
        device->w[local_y] += result;
    } else {
        device->w[local_y] -= result;
    }
    
    // Update global variable
    global_x = global_x - (thread_id % 2 == 0 ? 1 : -1) * blockDim.x;
    global_y = global_y - (thread_id % 2 == 0 ? 1 : -1) * blockDim.x;
    
    // Print result
    printf("x = %d, y = %d, z = %d\n", global_x, global_y, global_z);
}