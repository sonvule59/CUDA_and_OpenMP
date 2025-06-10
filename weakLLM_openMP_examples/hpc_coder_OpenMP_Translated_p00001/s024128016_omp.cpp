#include<vector>
#include<iostream>
#include<algorithm>
#include<omp.h>
using namespace std;

int main(){
  vector<int> a;
  a.resize(10);
  for(int i=0;i<10;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  #pragma omp parallel num_threads(4)
  {
    #pragma omp for
    for(int i=0;i<10;i++){
      cout<<a[i]<<endl;
    }
  }
}