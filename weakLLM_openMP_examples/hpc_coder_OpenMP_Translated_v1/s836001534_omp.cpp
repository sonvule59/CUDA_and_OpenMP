#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <queue>
#include <omp.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,b,n) for(int i=b;i<n;i++)

const float PI = 3.1415926;
static const int INFTY = (1<<30);

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  #pragma omp parallel for collapse(2)
  REP(i,1,10)
    REP(j,1,10)
    cout << i<<'x'<<j<<'='<<i*j<<endl;
  return 0;
}