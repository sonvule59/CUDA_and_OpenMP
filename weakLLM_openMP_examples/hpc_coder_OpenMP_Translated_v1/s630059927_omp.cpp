#include<iostream>
#include<omp.h>
using namespace std;
int main() {
	int a, b;
	#pragma omp parallel for private(a, b)
	for (a = 1; a <= 9; a++) {
		for (b = 1; b <= 9;b++) {
			cout << a << "x" << b << "=" << a*b << "\n";
		}
	}
        char c;
        cin>>c;
	return 0;
}