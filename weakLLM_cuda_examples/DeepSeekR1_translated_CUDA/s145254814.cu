__global__ i, __global__ j, __global__ i*j;
printf("%dx%d=%d\n", __global__i, __global__j, __global__i*j);
return 0;
</think>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i, j;
	for(i=1;i<10;i++) {
		for(j=1;j<10;j++) {
			printf("%dx%d=%d\n", i, j, i*j);
		}
	}
	return 0;
}

__global__ i, __global__ j, __global__ i*j;
printf("%dx%d=%d\n", __global__i, __global__j, __global__i*j);
return 0;