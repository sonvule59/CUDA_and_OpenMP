#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>
#include <omp.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
inline int mal(int x,int y){
  return x*y;
}
int main(void){
  #pragma omp parallel for collapse(2)
  FOR(i,1,10)FOR(j,1,10){
    printf("%dx%d=%d\n",i,j,mal(i,j));
  }
  return 0;
}