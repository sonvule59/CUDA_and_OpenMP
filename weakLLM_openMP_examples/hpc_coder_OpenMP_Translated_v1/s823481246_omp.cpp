#include<bits/stdc++.h>
#define ll long long int
#define FOR(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n)
using namespace std;
 
/*--------------------template--------------------*/

int main(){
    #pragma omp parallel for collapse(2)
    REP1(i,10){
        REP1(j,10){
            cout << i << 'x' << j << '=' << i*j << endl;
        }
    }
}