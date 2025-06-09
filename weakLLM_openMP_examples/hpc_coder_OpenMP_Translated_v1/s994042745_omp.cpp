#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9 + 7, MOD = 1e9 + 7;
const long long LINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
#pragma omp parallel for
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << i << "x" << j << "=" << i * j << endl;
		}
	}
	return 0;
}