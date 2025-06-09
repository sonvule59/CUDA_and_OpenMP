#include "bits/stdc++.h"

#define debug(x) cout<<#x<<": "<<x<<endl
#define rep(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef long long ll;


void solve() {
#ifdef _WIN32
	istream &cin = ifstream("input.txt");
#endif

#pragma omp parallel for
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cout << i << "x" << j << "=" << i * j << endl;
		}
	}
}




int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	solve();
#ifdef _WIN32
	system("PAUSE");
#endif
	return 0;
}