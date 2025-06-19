#include <stdio.h>
#include <stdlib.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)

#define PI 3.14159265358479

__global__ void kernel(int *a, int *b){
	REP(i, 9){
		REP(j, 9){
			printf("%d x %d = %d\n", i + 1, j + 1, (i + 1)*(j + 1));
		}
	}
}

int main(){
	int *a, *b;
	int size = sizeof(int) * 9 * 9;
	a = (int *)malloc(size);
	b = (int *)malloc(size);
	REP(i, 9){
		REP(j, 9){
			a[i * 9 + j] = i + 1;
			b[i * 9 + j] = j + 1;
		}
	}
	kernel<<<1, 1>>>(a, b);
	cudaDeviceSynchronize();
	free(a);
	free(b);
	return 0;
}