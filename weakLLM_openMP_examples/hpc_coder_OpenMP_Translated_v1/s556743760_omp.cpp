#include <cstdio>
#include <iostream>
#include <queue>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <map>
#include <omp.h>

#ifdef __BORLANDC__
	typedef __int64 Long;
#else 
	typedef long long Long;
#endif

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) b = min(a, b)
#define pb push_back
#define mp make_pair

using namespace std;

int main(){
	rep(i, 9) rep(j, 9){
		Long a = i + 1;
		Long b = j + 1;
		cout << a << "x" << b << "=" << a * b << endl;
	}
	
	#pragma omp parallel for
	rep(i, 9) rep(j, 9){
		Long a = i + 1;
		Long b = j + 1;
		cout << a << "x" << b << "=" << a * b << endl;
	}
	
	return (0);
}