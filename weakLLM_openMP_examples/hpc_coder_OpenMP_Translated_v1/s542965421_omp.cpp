#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1000000000;
const ll LINF = (ll) 4000000000000000000;
const ll MOD = (ll) 1000000007;
const double PI = acos(1.0);
const int limit = 100010;

#define REP(i,m,n) for(ll i = m; i < (ll)(n); i++)
#define rep(i,n) REP(i, 0, n)
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define NP(v) next_permutation(v.begin(),v.end())
#define smaller_queue  priority_queue <ll, vector<ll>, greater<ll> >
//------------------------------------------------------

int main() {

    REP(i, 1, 10) REP(j, 1, 10) {
        printf("%dx%d=%d\n", i, j, i * j);
    }

    #pragma omp parallel for
    for(ll i = 1; i < 10; i++) {
        for(ll j = 1; j < 10; j++) {
            printf("%dx%d=%d\n", i, j, i * j);
        }
    }

    return 0;
}