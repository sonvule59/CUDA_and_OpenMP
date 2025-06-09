#include <iostream>
#include <omp.h>

int main(){
  #pragma omp parallel for
  for(auto i=1; i<=9; ++i){
    for(auto j=1; j<=9; ++j){
      std::cout << i << "x" << j << "=" << i*j << "\n";
    }
  }
  return 0;
}