#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <omp.h>

using namespace std;

#define str to_string
#define rep(i, n) for (int i=1; i<int(n); i++)
#define all(c) (c).begin(), (c).end()


int main() {
  #pragma omp parallel for
  rep(i, 10) rep(j, 10) cout << i << "x"<<j<<"="<<i*j<<"\n";
  return 0;
}