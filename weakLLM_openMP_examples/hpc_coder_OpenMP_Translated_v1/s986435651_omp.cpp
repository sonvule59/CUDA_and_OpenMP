#include<iostream>
#include<omp.h>
using namespace std;

int main() {
	int x, y;
	#pragma omp parallel for private(x, y)
	for (x = 1; x <= 9; x = x + 1) {
		for (y = 1; y <= 9; y = y++) {
			cout << x << "x" << y << "=" << x*y << '\n';
		}
	}

	return 0;
}