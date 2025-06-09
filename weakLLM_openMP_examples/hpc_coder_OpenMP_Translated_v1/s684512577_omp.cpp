#include <bits/stdc++.h>
#ifdef dbg
#include "./printer.hpp"
#else
#define dump(x) void(0)
#endif

using namespace std;
#define ll long long
inline long  toInt(string s) {long  v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
#define INF 100000
int main(){
  ios_base::sync_with_stdio(0);

  #pragma omp parallel for
  for(ll i = 1; i < 10; i++){
    for(ll k = 1; k < 10; k++){
      printf("%dx%d=%d\n",i,k,i*k);
    }
  }

  return 0;

}