#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <omp.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
	#pragma omp parallel for
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}
	return 0;
}