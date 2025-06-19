#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

__global__ void expr(int x, int y, string* c) {
    stringstream ss;
    ss << x << "x" << y << "=" << x*y;
    c[threadIdx.x] = ss.str();
}

int main() {
    set<string> c;
    for (int i=1e3; i; --i) {
        c.insert(expr(rand() % 9 + 1, rand() % 9 + 1));
    }
    for (auto it=c.begin(); it<c.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}