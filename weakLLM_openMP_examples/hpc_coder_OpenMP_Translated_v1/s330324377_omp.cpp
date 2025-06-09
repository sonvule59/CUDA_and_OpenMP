#include <bits/stdc++.h>
#include <omp.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;
typedef vector<int> vi;

int main(){
    #pragma omp parallel for collapse(2)
    FOR(i, 1, 10) FOR(j, 1, 10) cout << i << "x" << j << "=" << i*j << endl;
}