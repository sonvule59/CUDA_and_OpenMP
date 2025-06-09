#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int  MOD=1000000007;
const int  INF= int(1e9);

int main()
{
	ios_base::sync_with_stdio(false);
    #pragma omp parallel for
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            cout<<i<<"x"<<j<<"="<<i*j<<endl;
        }
    }
	return 0;

}