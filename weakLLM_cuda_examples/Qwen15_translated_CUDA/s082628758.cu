__global__ void kernel(int n, int m)
{
    int thread_id = threadIdx.x + blockIdx.x * blockDim.x;

    if(thread_id < n && thread_id < m)
    {
        int x = threadIdx.x;
        int y = threadIdx.y;

        // Calculate product of x and y for each element
        int product = x * y;

        // Store product in local memory
        int global_product = product;

        // Update global product on all threads
        global_product += n * m;
        
        // Write global product to output device
        __syncthreads();
        global_product /= blockDim.x * blockDim.y;
        cudaMemcpy(&output[n*m], &global_product, sizeof(int), cudaMemcpyDeviceToHost);

        // Disable synchronization after writing global product to output device
        __syncthreads();

        // Print result
        printf("x = %d, y = %d, Product = %d\n", x, y, product);
    }
}