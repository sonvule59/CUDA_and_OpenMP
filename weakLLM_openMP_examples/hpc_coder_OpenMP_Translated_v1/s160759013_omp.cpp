#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#define int long long
inline int in() { int32_t x; scanf("%d", &x); return x ;}
using namespace std;
const int INF = 1e18;
const int MAX_N = 1e5 + 5;
int32_t main()
{
    #pragma omp parallel for
    for (int i = 1 ; i <= 9 ; i ++)
    {
        for (int x = 1 ; x <= 9 ; x ++)
        {
//            printf("%d*%d=%d",i,x,i*x);
            cout << i << "x" << x << "=" << i * x;
            cout << endl;
        }
    }
}