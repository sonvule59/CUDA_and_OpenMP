#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
#include <omp.h>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i<(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair
#define PB push_back


main(){
  #pragma omp parallel for
  rep(i,9)rep(j,9){
    cout<<i+1<<"x"<<j+1<<"="<<(i+1)*(j+1)<<endl;
  }
}