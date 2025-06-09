#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

typedef long int lint;
typedef long long int llint;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<long, long> pll;

#define EACH(t, c) for (auto&& t : c)
#define ALL(c) begin(c), end(c)
#define FOR(i, s, e) for (int i = (s); i < (int)(e); ++i)
#define REP(i, n) FOR(i, 0, n)
#define endl '\n'
#define fk first
#define sv second

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int MOD = (int)1e9 + 7;
const int INF = 999999999;

template<typename T>
void print(const std::vector<T>& v, char sep=' ') {
  for (int i = 0; i < (int)v.size(); i++) {
    if (i != 0) cout << sep;
    cout << v[i];
  }
  cout << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  #pragma omp parallel for collapse(2)
  REP(i, 9) {
    REP(j, 9) {
      cout << (i + 1) << "x" << (j + 1) << "=" << (i + 1) * (j + 1) << endl;
    }
  }
}