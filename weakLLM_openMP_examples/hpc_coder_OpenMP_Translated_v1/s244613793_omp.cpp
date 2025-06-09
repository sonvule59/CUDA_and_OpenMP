#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
#define rep(i,n) for(int i=1; i<=n; i++)
int main(){
    #pragma omp parallel for
    rep(i,9){
        rep(j,9){
            cout << i << 'x' << j << '=' << i*j << endl;
        }
    }
    return 0;
}