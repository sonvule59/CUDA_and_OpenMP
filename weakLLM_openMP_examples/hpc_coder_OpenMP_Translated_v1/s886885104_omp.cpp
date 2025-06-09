#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<omp.h>
using namespace std;

int main(){
  int a=1,b=1;
  #pragma omp parallel for
  for(int i=0;i<9;i++){
    cout<<a<<"x"<<b<<"="<<a*b<<endl;
    if(b==9){
      b=1,a++;
    }else{
      b++;}
  }
  cout<<"9x9=81"<<endl;

  return 0;
}