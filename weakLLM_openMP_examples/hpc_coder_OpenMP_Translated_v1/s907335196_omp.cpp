#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <omp.h>
using namespace std;
typedef long long int ll;
const int INF = 100000000;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
int main(){
    const int n = 9;
    #pragma omp parallel for
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%dx%d=%d\n", i, j, i*j);
        }
    }
    return 0;
}