#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}


int main() {
    #pragma omp parallel for collapse(2)
    for(int i = 1; i <= 10; ++i){
        for(int j = 1; j <= 10; ++j){
            cout << i << 'x' << j << '=' << i*j << endl;
        }
    }
    return 0;
}