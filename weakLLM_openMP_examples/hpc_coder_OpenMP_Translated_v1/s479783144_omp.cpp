#include <iostream>
#include <omp.h>
using namespace std;

int main() {
  int a = 1;
  int b = 1;
  #pragma omp parallel for
  for (;a < 10 && b <= 9;) {
    cout << b << "x" << a << "=" << a*b << endl;
    ++a;
    if (a == 10 && b <= 8) {
    ++b;
    a = 1;
    }
  }
}