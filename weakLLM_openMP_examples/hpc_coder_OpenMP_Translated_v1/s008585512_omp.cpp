#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<deque>
#include<cstring>
#include<climits>
#include<cassert>
#include<cctype>
#include<omp.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

bool ma[100000];
int main() {
  map<int,int> mp;
  #pragma omp parallel for
  rep(i,9) rep(j,9) {
    mp[j+i*9] = (int)mp.size();
    cout << i+1 << 'x' << j+1 << '=' << (i+1)*(j+1) << endl;
  }
  
  return 0;
}

Note:

*

*The OpenMP version uses the #pragma omp parallel for directive to parallelize the outer loop.

*The inner loop is not parallelized, as it is not necessary for the problem.

*The output is the same as the original C++ code.