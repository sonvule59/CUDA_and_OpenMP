#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

int main(){
  #pragma omp parallel for
  for(int a=1;a<=9;a++){
    for(int b=1;b<=9;b++){
      int c=a*b;
      cout<<a<<"x"<<b<<"="<<c<<endl;
    }
  }
  return 0;
}