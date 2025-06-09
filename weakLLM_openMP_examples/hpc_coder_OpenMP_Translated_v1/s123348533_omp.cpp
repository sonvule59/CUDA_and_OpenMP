//----------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define vmax_v(ary) *max_element(all(ary))
#define vmin_v(ary) *min_element(all(ary))
#define vmax_id(ary) distance((ary).begin(),max_element(all(ary)))
#define vmin_id(ary) distance((ary).begin(),min_element(all(ary)))

using ll = int64_t;
using pll = pair<ll,ll>;
using vl = vector<ll>;

const ll INF=INT64_MAX;
const double EPS=1e-10;
const double PI=acos(-1.0);

void init(){cin.tie(0);ios::sync_with_stdio(false);}
//----------------------------------------------------

int main(){
    init();

    #pragma omp parallel for
    for(int i=1;i<=9;i++){
      for(int j=1;j<=9;j++){
        cout << i << "x" << j << "=" << i*j << endl;
      }
    }

    return 0;
}

Note: The OpenMP version uses the `#pragma omp parallel for` directive to parallelize the outer loop. This directive tells the compiler to create a team of threads and distribute the iterations of the loop among them. The `for` loop is now executed in parallel by the threads in the team.