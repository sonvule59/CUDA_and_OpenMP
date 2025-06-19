__global__ void print_matrix(int i, int j, int n) {
    // Global variables
    int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
    int row = threadIdx.y + blockIdx.y * blockDim.y;
    int col = threadIdx.z + blockIdx.z * blockDim.z;

    // Check if the index is within the matrix dimensions
    if (row >= 0 && row < n && col >= 0 && col < n)
    {
        // Calculate the dot product of two elements at this position
        int dot_product = i * j * n;

        // Store the dot product in a local variable
        int element = dot_product / n;

        // Print the element on the screen
        std::cout << "Element " << element << "\n";
    }
}