__global__ void add(xpu_t x, ypu_t y) {
    int a = threadIdx.x + blockIdx.x * blockDim.x;
    int b = threadIdx.y + blockIdx.y * blockDim.y;
    
    if (a < 9 && b < 9) {
        x[a] += y[a];
        y[b] += x[b];
    }
}

int main() {
    dim3 threads(2, 2, 1); // grid size of 2x2x1
    dim3 block_size(1, 1, 1); // block size of 1x1x1
    
    xpu_t x[9], y[9];
    
    add<<<threads, block_size>>>(x, y);
    
    for (int i = 0; i < 9; i++) {
        cout << "Element at thread " << i << ": " << x[i] << ' ' << y[i] << endl;
    }
    
    return 0;
}