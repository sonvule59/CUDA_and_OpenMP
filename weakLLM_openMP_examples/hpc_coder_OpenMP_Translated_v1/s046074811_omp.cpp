#include<bits/stdc++.h>
const long long INF = INT_MAX / 2;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define ll long long int
using namespace std;
ll ans = 0, sum = 0, n, k, cnt = 0, w, h;
string s;
vector<ll> v;
vector < pair<ll, ll > > vp;
vector<vector<ll> > vv(50, vector<ll>(50, INF));
vector<string> vs;
vector<char> vc;
set<ll> st;
map<char, ll> mp;

/*--------------------template--------------------*/

int main()
{
#pragma omp parallel for reduction(+:ans)
	REP1(i,10)
	{
		REP1(j,10)
		{
			ans += i*j;
		}
	}
	cout << ans << endl;
}