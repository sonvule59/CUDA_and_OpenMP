#include<iostream>
using namespace std;

__global__ void sort(int *mh, int N){
	int t;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			if(mh[i] < mh[j]){
				t = mh[i];
				mh[i] = mh[j];
				mh[j] = t;
			}
		}
	}
}

int main(){
	int N = 10;
	int t;
	int mh[N];
	
	for(int i=0; i<10; i++){
		cin >> t;
		if(t>=0 && t<=10000)
			mh[i]=t;
		else{
			i=i-1;
		}
	}
	
	int *d_mh;
	cudaMalloc((void **)&d_mh, N*sizeof(int));
	cudaMemcpy(d_mh, mh, N*sizeof(int), cudaMemcpyHostToDevice);
	
	sort<<<1,1>>>(d_mh, N);
	
	cudaMemcpy(mh, d_mh, N*sizeof(int), cudaMemcpyDeviceToHost);
	
	for(int i=0; i<3; i++)
		cout << mh[i] << "\n";
	
	cudaFree(d_mh);
	
	return 0;
}