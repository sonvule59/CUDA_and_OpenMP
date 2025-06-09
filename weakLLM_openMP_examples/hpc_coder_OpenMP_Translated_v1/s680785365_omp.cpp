#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
#define MOD 1000000007
#define INF 999999999
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define SORT(c) sort((c).begin(),(c).end())
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> Vi;
int a[100][100];
int main(){
  #pragma omp parallel for collapse(2)
  FOR(i,1,10){
	  FOR(j,1,10){
		  printf("%dx%d=%d\n",i,j,i*j);
	  }
  }
  return 0;
}