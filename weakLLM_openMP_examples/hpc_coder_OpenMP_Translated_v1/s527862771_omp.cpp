#include <omp.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
#pragma omp parallel for
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}
	return 0;
}