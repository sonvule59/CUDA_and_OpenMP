#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#include<omp.h>
using namespace std;

int main(){
    int mod=1000000007;
    int n,m;
    #pragma omp parallel for
    for (int i=1;i<10;i++) {
        for (int j=1;j<10;j++) {
            printf("%dx%d=%d\n",i,j,i*j);
        }
    }
    return 0;
}