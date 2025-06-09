#include <iostream>
#include <omp.h>
using namespace std;

#define REP(i,n,m) for(int i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

int main(void){
	#pragma omp parallel for
	rep(i,10){
		rep(j,10){
			cout<<i<<"x"<<j<<"="<<i*j<<endl;
		}
	}

	return 0;
}