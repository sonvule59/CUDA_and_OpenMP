#include<iostream>
#include<omp.h>
using namespace std;

int main() {
	int a,b,c;
	#pragma omp parallel for private(a,b,c)
	for(a = 1;a <= 9;a++) {
		for(b = 1;b <= 9;b++) {
			c = a * b;
			cout << a << "x" << b << "=" << c << endl;
		}
	}
	return 0;
}