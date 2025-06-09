#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long

#define INF 999999999

using namespace std;

int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};
// input

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    #pragma omp parallel for
    FOR(i, 1, 10)
    {
        FOR(j, 1, 10)
        {
            cout << i << "x" << j << "=" << i * j << "\n";
        }
    }
}