#include<iostream>
#include<omp.h>
using namespace std;

int main(void) {
	#pragma omp parallel for
	for (int i = 1; i <= 9; i++) {
		for (int t = 1; t <= 9; t++) {
			cout << i << "x" << t<<"="<<i*t<<"\n";
		}
	}
	return 0;
}