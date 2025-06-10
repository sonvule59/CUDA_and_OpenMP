#include<iostream>
#include<vector>
#include<algorithm>
#include<omp.h>
using namespace std;

int main(){
  int a;
  vector<int> v;

  #pragma omp parallel for
  for (unsigned int i = 0; i < 10; i++) {
    cin >> a;
    v.push_back(a);
    if (cin.eof()) { break; }
  }

  sort(v.begin(), v.end(), greater<int>());

  #pragma omp parallel for
  for (unsigned int i = 0; i < 3; i++) {
    cout << v[i] << endl;
  }

  return 0;
}