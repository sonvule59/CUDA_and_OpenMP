#include <bits/stdc++.h>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
const int INF = 1e9;

using namespace std;
int main(){
    REP(i, 9) REP(j, 9)
        cout << i+1 << "x" << j+1 << "=" << (i+1) * (j+1) << endl;
    return 0;
}