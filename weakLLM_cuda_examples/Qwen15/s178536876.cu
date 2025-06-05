__global__ void kernel(float *a, float *b, int n)
{
    int tid = threadIdx.x + blockIdx.x * blockDim.x;

    if(tid < n)
    {
        float sum = 0.0f;
        
        for(int i = tid; i < n; i += blockDim.x * gridDim.x)
        {
            sum += a[i] * b[i];
        }
        
        // Store result in host memory
        a[tid] = sum;
    }
}