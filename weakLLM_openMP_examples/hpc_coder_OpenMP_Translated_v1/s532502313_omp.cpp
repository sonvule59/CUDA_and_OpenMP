#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i,N) for(int i = 0; i < (int)N; i++)

int main(){
#pragma omp parallel for
	REP(i,9)REP(j,9)cout << i+1 << "x" << j+1<< "=" << (i+1)*(j+1) << endl;
	return 0;
}