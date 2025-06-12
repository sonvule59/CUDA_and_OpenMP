#include<iostream>
  using namespace std;
   __global__ void sort(int *a, int n)
   {
       int temp;
       for(int i=0; i<n; i++)
       {
           for(int j=0; j<n;j++)
           {
           if(a[i] > a[j])
           {
             temp=a[i];
             a[i]=a[j];
             a[j]=temp;
           }
         }
       }
   }
   int main(){
      int a[10];
      int temp;
      for(int m=0; m<10; m++)
      {
          cin >> a[m];
      }
      int *d_a;
      cudaMalloc((void **)&d_a, 10*sizeof(int));
      cudaMemcpy(d_a, a, 10*sizeof(int), cudaMemcpyHostToDevice);
      sort<<<1,1>>>(d_a, 10);
      cudaMemcpy(a, d_a, 10*sizeof(int), cudaMemcpyDeviceToHost);
      for(int k=0; k<3; k++)
      {
          cout << a[k]<< endl;
      }
      cudaFree(d_a);
   }