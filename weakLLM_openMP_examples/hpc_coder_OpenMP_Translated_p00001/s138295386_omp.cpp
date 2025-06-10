#include <iostream>
#include <algorithm>
#include <vector>
#include <omp.h>
using namespace std;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int i, input;
  vector<int> heights;
  for (i = 0; i < 10; i++) {
    cin >> input;
    heights.push_back(input);
  }

  sort(heights.rbegin(), heights.rend());

  #pragma omp parallel
  {
    #pragma omp single
    {
      cout << heights.at(0) << endl;
      cout << heights.at(1) << endl;
      cout << heights.at(2) << endl;
    }
  }

  return 0;
}