#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef pair<int,int> P;

int main(){
#pragma omp parallel for
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}
}