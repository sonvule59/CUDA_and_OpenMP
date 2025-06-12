c++
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> q1;
__global__ void kernel(int *arr, int n){
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	if(i < n){
		q1.push(arr[i]);
	}
}
int main(){
	int i,j;
	int arr[10];
	for(i=0;i<10;i++){
		cin>>j;
		arr[i] = j;
	}
	int n = 10;
	int blockSize = 10;
	int numBlocks = (n + blockSize - 1) / blockSize;
	kernel<<<numBlocks, blockSize>>>(arr, n);
	for(i=0;i<3;i++){
		cout<<q1.top()<<endl;
		q1.pop();
	}
	return 0;
}