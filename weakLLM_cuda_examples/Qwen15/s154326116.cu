#include <cuda_runtime.h>

__global__ void QQ(int a, int b) {
    // Check if a is greater than or equal to 10
    if (a >= 10) {
        return;
    }

    // Check if b is less than or equal to 10
    if (b < 10) {
        printf("x%d x%d = %d\n", a, b, a * b);
        
        // Call QQ function on a larger block with b + 1
        QQ(a, b + 1);

        // Call QQ function again on a smaller block with a + 1
        QQ(a + 1, 1);
    } else {
        // If b is greater than or equal to 10, call QQ function on a block with a + 1
        QQ(a + 1, 1);
    }
}

int main() {
    // Create a CUDA device context
    cudaDeviceProp prop;
    cudaGetDeviceProperties(&prop, 0);

    // Get the number of threads per block
    int numBlocks = prop.multiProcessorCount / prop.deviceSize;

    // Allocate memory for the block sizes
    int blockSize[2] = {16, 32};

    // Initialize the block sizes
    cudaMemcpy(blockSize, blockSize, sizeof(blockSize), cudaMemcpyHostToDevice);

    // Create a kernel object
    kernel<<<numBlocks, 1>>>(blockSize, &QQ);

    // Launch the kernel
    kernelLaunch<<<numBlocks, 1>>>(blockSize, &QQ);

    // Read the results from the host
    int result[2];
    cudaMemcpy(result, QQ.get(), sizeof(result), cudaMemcpyDeviceToHost);

    // Print the results
    printf("QQ result:\n");
    for (int i = 0; i < 2; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}