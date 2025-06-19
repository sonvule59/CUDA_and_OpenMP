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

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

bool ma[100000];
int main() {
  map<int,int> mp;
  rep(i,9) rep(j,9) {
    mp[j+i*9] = (int)mp.size();
    printf("%d x %d = %d\n", i+1, j+1, (i+1)*(j+1));
  }
  
  return 0;
}