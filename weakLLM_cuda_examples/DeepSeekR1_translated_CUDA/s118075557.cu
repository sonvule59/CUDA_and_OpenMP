#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<n;i++)

int main(){
    int i,k;
    rep(i,9){
        rep(k,9){
            printf("%dx%d=%d\n",i+1,k+1,(i+1)*(k+1));
        }
    }
    return 0;
}