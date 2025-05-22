#include <cuda_runtime.h>
#include <stdint.h>
#include <stdio.h>

// Device function that does the padding
__device__ void paddingChar(unsigned char *P, uint64_t dataBlockSize, uint64_t paddingSize) {
    P[dataBlockSize] = 0x80;
    for (int i = 1; i <= paddingSize - 9; i++) {
        P[dataBlockSize + i] = 0x00;
    }
    for (int i = 1; i <= 8; i++) {
        P[dataBlockSize + paddingSize - i] = (unsigned char)((8 * dataBlockSize) >> ((i - 1) * 8));
    }
}

// CUDA kernel: each thread applies padding to one data block
__global__ void paddingKernel(unsigned char *P, uint64_t *dataBlockSizes, uint64_t *paddingSizes, int numBlocks) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < numBlocks) {
        unsigned char *blockPtr = P + idx * (dataBlockSizes[idx] + paddingSizes[idx]);
        paddingChar(blockPtr, dataBlockSizes[idx], paddingSizes[idx]);
    }
}

int main() {
    const int numBlocks = 1;
    uint64_t dataBlockSize = 56;
    uint64_t paddingSize = 64 - dataBlockSize;
    size_t totalSize = dataBlockSize + paddingSize;

    // Host memory
    unsigned char *h_P = new unsigned char[totalSize];
    uint64_t *h_dataBlockSizes = new uint64_t[numBlocks];
    uint64_t *h_paddingSizes = new uint64_t[numBlocks];

    h_dataBlockSizes[0] = dataBlockSize;
    h_paddingSizes[0] = paddingSize;

    // Fill initial data
    for (int i = 0; i < dataBlockSize; i++) {
        h_P[i] = (unsigned char)(i + 1);
    }

    // Device memory
    unsigned char *d_P;
    uint64_t *d_dataBlockSizes, *d_paddingSizes;

    cudaMalloc(&d_P, totalSize);
    cudaMalloc(&d_dataBlockSizes, sizeof(uint64_t) * numBlocks);
    cudaMalloc(&d_paddingSizes, sizeof(uint64_t) * numBlocks);

    // Copy host to device
    cudaMemcpy(d_P, h_P, totalSize, cudaMemcpyHostToDevice);
    cudaMemcpy(d_dataBlockSizes, h_dataBlockSizes, sizeof(uint64_t) * numBlocks, cudaMemcpyHostToDevice);
    cudaMemcpy(d_paddingSizes, h_paddingSizes, sizeof(uint64_t) * numBlocks, cudaMemcpyHostToDevice);

    // Launch kernel
    paddingKernel<<<1, 1>>>(d_P, d_dataBlockSizes, d_paddingSizes, numBlocks);
    cudaDeviceSynchronize();

    // Copy result back to host
    cudaMemcpy(h_P, d_P, totalSize, cudaMemcpyDeviceToHost);

    // Print result
    printf("Padded Block:\n");
    for (int i = 0; i < totalSize; i++) {
        printf("%02x ", h_P[i]);
    }
    printf("\n");

    // Cleanup
    delete[] h_P;
    delete[] h_dataBlockSizes;
    delete[] h_paddingSizes;
    cudaFree(d_P);
    cudaFree(d_dataBlockSizes);
    cudaFree(d_paddingSizes);

    return 0;
}


// #include <cuda_runtime.h>
// #include <stdint.h>

// __device__ void paddingChar(unsigned char *P, uint64_t dataBlockSize, uint64_t paddingSize) {
//     // Step 1: Set the first byte after the data block to 0x80
//     P[dataBlockSize] = 0x80;

//     // Step 2: Fill with 0x00 up to paddingSize - 9
//     for (int i = 1; i <= paddingSize - 9; i++) {
//         P[dataBlockSize + i] = 0x00;
//     }

//     // Step 3: Append the 64-bit length of the input in bits at the end
//     for (int i = 1; i <= 8; i++) {
//         P[dataBlockSize + paddingSize - i] =
//             (unsigned char)((8 * dataBlockSize) >> (8 * (i - 1)));
//     }
// }

// __global__ void paddingCharKernel(unsigned char *P, uint64_t dataBlockSize, uint64_t paddingSize) {
//     // Only use one thread here since padding is done sequentially
//     if (threadIdx.x == 0 && blockIdx.x == 0) {
//         paddingChar(P, dataBlockSize, paddingSize);
//     }
// }

// int main() {
//     uint64_t dataBlockSize = 64;     // example size
//     uint64_t paddingSize = 64;       // example padding

//     // Allocate host memory
//     unsigned char *h_P = new unsigned char[dataBlockSize + paddingSize]{};

//     // Allocate device memory
//     unsigned char *d_P;
//     cudaMalloc(&d_P, dataBlockSize + paddingSize);
//     cudaMemcpy(d_P, h_P, dataBlockSize + paddingSize, cudaMemcpyHostToDevice);

//     // Launch kernel
//     paddingCharKernel<<<1, 1>>>(d_P, dataBlockSize, paddingSize);
//     cudaDeviceSynchronize();

//     // Copy result back to host
//     cudaMemcpy(h_P, d_P, dataBlockSize + paddingSize, cudaMemcpyDeviceToHost);

//     // Free memory
//     cudaFree(d_P);
//     delete[] h_P;

//     return 0;
// }
