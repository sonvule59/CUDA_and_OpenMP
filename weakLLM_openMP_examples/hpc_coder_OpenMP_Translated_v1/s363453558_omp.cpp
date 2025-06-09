#include <bits/stdc++.h>
#define LL long long
//#define rep(i,n) for (int i=0;i<(n);i++)
#define rep(i,x,n) for (int i=x;i<(n);i++)
using namespace std;
int main(){
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	#pragma omp parallel for collapse(2)
	rep(i,1,10){
		rep(j,1,10){
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}
	return 0;
}