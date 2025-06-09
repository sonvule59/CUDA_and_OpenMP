#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <omp.h>

#define REP(i, n) for(int i = 0;i < (n); i++)
#define REP2(i, x, n) for(int i = (x); i < (n); i++)
#define REPR(i, n) for(int i = (n); i >= 0; i--)

#define ALL(a) (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

#define LL long long int
#define LD long double

#define PI 3.14159265358979

using namespace std;

//================================================
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	#pragma omp parallel for collapse(2)
	REP2(i, 1, 10) {
		REP2(j, 1, 10) {
			cout << i << "x" << j << "=" << i * j <<"\n";
		}
	}

	return 0;
}