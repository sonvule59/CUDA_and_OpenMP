#include<iostream>
#include<omp.h>

using namespace std;

int main() {
	int a = 0;
	int b = 0;
	int kake;

	#pragma omp parallel for
	for (int i=1; i<10; i++) {
		for (int j=1; j<10; j++) {
			kake = i * j;
			cout << i << "x" << j << "=" << kake << endl;
		}
	}
	return 0;
}