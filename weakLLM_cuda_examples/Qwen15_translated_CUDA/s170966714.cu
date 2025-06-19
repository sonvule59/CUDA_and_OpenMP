__global__ void printGrid(int n, int m) {
    // Global variables
    int grid[n][m];
    
    // Local variables
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    int col = blockIdx.y * blockDim.y + threadIdx.y;
    
    // Iterate over rows
    if(row < n && col < m) {
        grid[row][col] = i+1;
        
        // Check if it's a prime number
        if(isPrime(grid[row][col])) {
            cout << grid[row][col] << " ";
        }
    }
}