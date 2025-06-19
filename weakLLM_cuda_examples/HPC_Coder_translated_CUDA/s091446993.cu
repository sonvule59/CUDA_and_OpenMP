#include <bits/stdc++.h>
#define INT(name) int name; scanf("%d",&name);
#define VINT(name,n) vector<int> name(n); for(int i = 0;i < n;i++) scanf("%d",&name[i]);

using namespace std;

__global__ void print_multiplication_table(int *table, int n){
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if(idx < n){
		for(int i = 1;i <= 9;i++){
			printf("%dx%d=%d\n",i,table[idx],i*table[idx]);
		}
	}
}

int main(int argc, char const *argv[]){
	int n;
	scanf("%d",&n);
	VINT(table,n);
	print_multiplication_table<<<(n+255)/256,256>>>(table,n);
	cudaDeviceSynchronize();
	return 0;
}