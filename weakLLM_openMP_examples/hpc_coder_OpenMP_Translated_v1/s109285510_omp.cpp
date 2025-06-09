#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]) {
	int m, n;
	#pragma omp parallel for private(m, n)
	for (m = 1; m <= 9; ++m) {
		for (n = 1; n <= 9; ++n) {
			std::cout << m << 'x' << n << '=' << (m * n) << std::endl;
		}
	}
	return 0;
}