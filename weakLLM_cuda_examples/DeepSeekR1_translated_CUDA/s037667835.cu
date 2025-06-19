__exit__ is not a valid CUDA function. Return only CUDA code, no explanations or anything else.
</think>

#include<iostream>
#include<cuda.h>
#include<cmath>

__global__ void matrix_mult(int *A, int *B, int *C, int *D) {
    int i = 0, j = 0;
    while (i < 10) {
        while (j < 10) {
            *C += *A += *B += *D += i * j;
            i++;
            j++;
        }
    }
}

int main() {
    int *A = new int[10];
    int *B = new int[10];
    int *C = new int[10];
    int *D = new int[10];
    
    for (int i = 0; i < 10; i++) {
        A[i] = i;
        B[i] = i;
    }
    
    __global__ void matrix_mult(int *A, int *B, int *C, int *D) {
        int i = 0, j = 0;
        while (i < 10) {
            while (j < 10) {
                C[i*10 + j] += A[i*10 + j] += B[i*10 + j] += D[i*10 + j] += i * j;
                i++;
                j++;
            }
        }
    }
    
    __global__ void print_matrix(int *A, int *B, int *C, int *D) {
        int i = 0, j = 0;
        while (i < 10) {
            while (j < 10) {
                std::cout << A[i] << "x" << B[j] << "=" << A[i] * B[j] << "\n";
                i++;
                j++;
            }
        }
    }
    
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    
    return 0;
}