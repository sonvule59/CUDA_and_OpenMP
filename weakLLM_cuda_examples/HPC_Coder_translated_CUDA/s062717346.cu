#include<stdio.h>
#include<cuda.h>
#include<cuda_runtime.h>

__global__ void print_multiplication_table(int a, int b)
{
	printf("%dx%d=%d\n",a,b,a*b);
}

int main()
{
	int a=1,b=1;
	while(a<10&&b<10)
	{
		print_multiplication_table<<<1,1>>>(a,b);
		b++;
		if(b>9)
		{
			a++;
			b=1;
		}
	}
	cudaDeviceSynchronize();
	return 0;
}