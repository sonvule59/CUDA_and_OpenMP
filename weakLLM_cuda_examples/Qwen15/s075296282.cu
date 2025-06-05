__global__ void multiplyArrays(int* arrA, int* arrB, int size) {
    int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
    if(thread_id < size){
        int product = arrA[thread_id] * arrB[thread_id];
        __syncthreads();
        if(thread_id % 2 == 0){
            // If both threads have even number of elements, add them together
            int sum = product + arrA[thread_id+1] + arrB[thread_id+2];
            __syncthreads();
            // Update the product with the sum
            arrA[thread_id] = product;
            arrB[thread_id] = sum;
        } else {
            // If one thread has odd number of elements, subtract it from the other
            int difference = product - arrA[thread_id-1] - arrB[thread_id-2];
            __syncthreads();
            // Update the product with the difference
            arrA[thread_id] = product;
            arrB[thread_id] = difference;
        }
    }
}

int main() {
    int size = 9;
    int* arrA = new int[size];
    int* arrB = new int[size];

    // Initialize arrays with random values
    for (int i = 0; i < size; i++) {
        arrA[i] = rand() % 100;
        arrB[i] = rand() % 100;
    }

    // Multiply arrays on GPU
    multiplyArrays(arrA, arrB, size);

    // Print the result
    for (int i = 0; i < size; i++) {
        std::cout << arrA[i] << " x " << arrB[i] << "=" << arrA[i] * arrB[i] << std::endl;
    }

    delete[] arrA;
    delete[] arrB;

    return 0;
}