__global__ void kernel(int i, int r, int num) {
    int thread_id = threadIdx.x + blockIdx.x * blockDim.x;
    if(thread_id < r) {
        int temp = num * thread_id;
        printf("thread %d x %d = %d\n", thread_id, r, temp);
    }
}