#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int main(){
	REP(i,9){
	    REP(j,9){
	        cout<<i+1<<"x"<<j+1<<"="<<(i+1)*(j+1)<<endl;
	    }
	}
	#pragma omp parallel for
	FOR(i,0,9){
	    FOR(j,0,9){
	        cout<<i+1<<"x"<<j+1<<"="<<(i+1)*(j+1)<<endl;
	    }
	}
	return(0);
}