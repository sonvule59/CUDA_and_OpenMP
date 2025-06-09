#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
auto solve(){
#pragma omp parallel for
for(int i=1; i<10; i++)
for(int j=1;j<10; j++)
cout << i << "x" << j << "=" << i*j << endl;
}
int main() {
solve();
return 0;
}