#include <iostream>
#include <cmath>
#include <omp.h>

#define SIZE 9

using namespace std;

void trace(int, int);

int main(void) {
	#pragma omp parallel for collapse(2)
	for (int i = 1; i <= SIZE; i++) {
		for (int j = 1; j <= SIZE; j++) {
			trace(i, j);
		}
	}
	return 0;
}

void trace(int a, int b) {
	cout << a << "x" << b << "=" << a*b << "\n";
}