#include <cstdint>
#include <iostream>
#include <omp.h>

using namespace std;

int32_t main()
{
  #pragma omp parallel for
  for (uint32_t i = 1; i <= 9; i++) {
    for (uint32_t j = 1; j <= 9; j++) {
      cout << i << "x" << j << "=" << i * j << endl;
    }
  }

  return 0;
}