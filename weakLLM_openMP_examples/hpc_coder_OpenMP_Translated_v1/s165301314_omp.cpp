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

int main() {
  map<int,int> mp;
  #pragma omp parallel for
  rep(i,9) rep(j,9) {
    mp[i] = (int)mp.size();
    cout << i+1 << 'x' << j+1 << '=' << (i+1)*(j+1) << endl;
  }
  
  return 0;
}