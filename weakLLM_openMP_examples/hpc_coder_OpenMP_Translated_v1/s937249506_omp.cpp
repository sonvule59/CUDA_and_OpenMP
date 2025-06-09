#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)
//#define INF (1LL<<59)

int main(){
    #pragma omp parallel for
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cout<<i<<"x"<<j<<"="<<i*j<<endl;
        }
    }
}