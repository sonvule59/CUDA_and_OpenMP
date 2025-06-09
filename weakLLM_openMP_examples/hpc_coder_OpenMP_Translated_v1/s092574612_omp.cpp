#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

#define FOR(i,l,r) for(int i = (l);i < (r);i++)
#define ALL(x) (x).begin(),(x).end()
template<typename T> bool chmax(T& a,const T& b){return a < b ? (a = b,true) : false;}
template<typename T> bool chmin(T& a,const T& b){return b < a ? (a = b,true) : false;}
typedef long long ll;

int main()
{
	#pragma omp parallel for
	for(int i = 1;i <= 9;i++){
		for(int j = 1;j <= 9;j++){
			printf("%dx%d=%d\n",i,j,i * j);
		}
	}

	return 0;
}