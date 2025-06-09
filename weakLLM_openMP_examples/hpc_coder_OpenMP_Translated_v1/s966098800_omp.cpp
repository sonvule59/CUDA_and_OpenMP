#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
struct edge{int to;ll cost;};
typedef pair<ll,int> P;
const ll INF=1000000000000LL;
const ll MOD=1000000007LL;
const ll MAX=100010;
int main(){
#pragma omp parallel for
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cout<<i<<"x"<<j<<"="<<i*j<<endl;
		}
	}
	return 0;
}