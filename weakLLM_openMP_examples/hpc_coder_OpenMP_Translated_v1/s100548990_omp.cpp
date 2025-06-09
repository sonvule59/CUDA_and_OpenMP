#include <iostream>
#include <omp.h>

using namespace std;

int main(){
	int m, n, q;

	#pragma omp parallel for private(m, n, q)
	for(m=1; m<10; m++){
		for(n=1; n<10; n++){
			q = m*n;
			cout << m << "x" << n << "=" << q << endl;
		}
	}
}