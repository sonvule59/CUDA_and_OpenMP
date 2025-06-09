#include <iostream>
#include <omp.h>
using namespace std;

int main() {
  #pragma omp parallel for
  for (size_t i = 1; i < 10; i++) {
    for (size_t j = 1; j < 10; j++) {
      std::cout << i << "x" << j << '=' << i * j << '\n';
    }
  }

  return 0;
}