#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
int main() {
  REP(i, 9) REP(j, 9) {
    #pragma omp parallel for
    for (int k = 1; k <= 9; k++) {
      cout << i << "x" << j << "=" << i * j << endl;
    }
  }
}