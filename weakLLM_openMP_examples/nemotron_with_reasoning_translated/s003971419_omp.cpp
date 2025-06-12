#include <bits/stdc++..h>
using namespace std;

int main() {
    vector<int> arr(100000);
    int i, j;
    FOR(i, 0, 100000) FOR(j, 0, 10) {
        arr[i] += arr[i] * j;
    }
    cout << "Done!" << endl;
    return 0;
}