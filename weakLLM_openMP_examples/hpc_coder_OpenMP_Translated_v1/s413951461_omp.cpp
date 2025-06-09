#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
  int i, j;
  #pragma omp parallel for private(i, j)
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      int seki = i * j;
      cout << i << "x" << j << "=" << seki << endl;
    }
  }

  return 0;
}