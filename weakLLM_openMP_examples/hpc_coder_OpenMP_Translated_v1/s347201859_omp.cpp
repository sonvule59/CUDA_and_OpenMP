#include<iostream>
#include<omp.h>
int main() {
	#pragma omp parallel for
	for (int i = 1; i <= 9; i += 1) {
		for (int j = 1; j < 10; j++) {
			std::cout << i << "x" << j <<"=" << i*j<< std::endl;
		}
	}
}