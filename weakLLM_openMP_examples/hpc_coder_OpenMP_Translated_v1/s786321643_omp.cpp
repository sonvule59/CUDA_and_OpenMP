#include <iostream>
#include <omp.h>

using namespace std;

int main() {
  #pragma omp parallel for
  for (int i = 1; i <= 9; i++)
    for (int k = 1; k <= 9; k++) cout << i << "x" << k << "=" << i * k << endl;
}