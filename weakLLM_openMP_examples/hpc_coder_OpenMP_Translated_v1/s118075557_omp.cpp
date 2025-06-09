#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

#define rep(i,n) for(i=0;i<n;i++)

int main(){
    int i,k;
    #pragma omp parallel for
    rep(i,9){
        rep(k,9){
            printf("%dx%d=%d\n",i+1,k+1,(i+1)*(k+1));
        }
    }
    return 0;
}