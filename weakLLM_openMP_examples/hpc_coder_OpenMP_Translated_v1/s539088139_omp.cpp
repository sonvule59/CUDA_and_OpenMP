#include <iostream>
#include <omp.h>
using namespace std;

// 1927426???1927428???WA???????????????????????????????????§???
void dodo() {
  #pragma omp parallel for
  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
      cout << i+1 << 'x' << j+1 << '=' << (i+1)*(j+1) << endl;
}

int main() {
  dodo();
  return 0;
}

The OpenMP version uses the `#pragma omp parallel for` directive to parallelize the outer loop. The inner loop is not parallelized, as it is not necessary for the problem. The output of the OpenMP version is the same as the original C++ version.