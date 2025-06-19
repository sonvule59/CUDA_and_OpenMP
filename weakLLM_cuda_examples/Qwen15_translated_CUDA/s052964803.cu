__global__ void print_i32(int* arr, int size) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if (tid < size) {
        int index = tid * blockDim.x + threadIdx.y;
        int value = arr[index];
        
        // Add some padding for alignment
        value += blockDim.x * gridDim.x * 4;
        
        // Write the result to a file
        FILE* file = fopen("output.txt", "w");
        fprintf(file, "%d ", value);
        fclose(file);
    }
}