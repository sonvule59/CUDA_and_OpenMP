#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int main(){
#pragma omp parallel for collapse(2)
rep(i,1,10) rep(j,1,10) {
printf("%dx%d=%d\n",i,j,i*j);
}
    return 0;
}