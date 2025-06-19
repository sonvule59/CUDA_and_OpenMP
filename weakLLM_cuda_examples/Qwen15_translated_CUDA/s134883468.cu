__global__ void print_matrix(int matrix[10][10], int size) {
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    if (index < size) {
        for (int jndex = 1; jndex < size; jndex++) {
            cout << matrix[index] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[10][10];
    // Initialize matrix with some values
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[0][3] = 4;
    matrix[0][4] = 5;
    matrix[0][5] = 6;
    matrix[0][6] = 7;
    matrix[0][7] = 8;
    matrix[0][8] = 9;
    matrix[0][9] = 10;

    int size = 10;
    // Print matrix on GPU using CUDA kernel
    print_matrix<<<gridDim=1, blockDim*x>>>(matrix, size);

    return 0;
}