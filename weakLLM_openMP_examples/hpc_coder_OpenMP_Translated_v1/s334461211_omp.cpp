//----------------------------------------------------
//HEADER
#include<bits/stdc++.h>
#include<omp.h>

//NAMESPACE
using namespace std;

//CONSTANT
const int64_t INF=INT64_MAX;

//FAST I/O
void init(){cin.tie(0);ios::sync_with_stdio(false);}
//----------------------------------------------------

int main(){
  init();

  #pragma omp parallel for
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      cout << i << "x" << j << "=" << i*j << endl;
    }
  }

  return 0;
}

//----------------------------------------------------