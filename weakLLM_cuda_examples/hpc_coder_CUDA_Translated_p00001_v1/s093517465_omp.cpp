#include <iostream>
using namespace std;
__global__ void sort(int *mount){
	int num = threadIdx.x;
	if(num<10){
	 for(int j=num+1;j<10;j++){
	  if(mount[num]<mount[j]){
	 	 int sub=mount[j];
	 	 mount[j]=mount[num];
	 	 mount[num]=sub;
	   }
     }
    }
}
int main(){
	int mount[10];
	for(int num=0;num<10;num++){
	 // cout << "Mount"<<num << endl;
	  cin >> mount[num];
    }
    int *d_mount;
    cudaMalloc((void **)&d_mount, 10*sizeof(int));
    cudaMemcpy(d_mount, mount, 10*sizeof(int), cudaMemcpyHostToDevice);
    sort<<<1,10>>>(d_mount);
    cudaMemcpy(mount, d_mount, 10*sizeof(int), cudaMemcpyDeviceToHost);
    for(int i=0;i<10;i++){
     cout << mount[i] << endl;
    }
    cudaFree(d_mount);
    return 0;
}