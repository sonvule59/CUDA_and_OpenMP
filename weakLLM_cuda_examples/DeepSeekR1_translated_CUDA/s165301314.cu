#include <iostream>
#include <cuda55.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <cuda55/optimization.h>

using namespace std;

int main() {
  map<int, int> mp;
  rep(i, 9) rep(j, 9) {
    mp[i] = (int)mp.size();
    cout << i + 1 << 'x' << j + 1 << '=' << (i + 1) * (j + 1) << endl;
  }
  
  return 0;
}