__global__ void kernel(float *A, float *B, int N) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if(tid<N) {
        float sum = 0;
        for(int i=0; i<N; i+= blockDim.x) {
            sum += A[i] * B[tid];
        }
        printf("Sum at thread %d: %f\n", tid, sum);
    }
}