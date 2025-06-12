#include <stdio.h>

__global__ void sort(int *arr, int n)
{
    int tid = threadIdx.x;
    int i = tid;
    int temp;

    while (i < n)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        i += blockDim.x * gridDim.x;
    }
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;
    int *d_arr;

    cudaMalloc((void **)&d_arr, n * sizeof(int));
    cudaMemcpy(d_arr, arr, n * sizeof(int), cudaMemcpyHostToDevice);

    sort<<<1, n>>>(d_arr, n);

    cudaMemcpy(arr, d_arr, n * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}