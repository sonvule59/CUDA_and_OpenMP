#include <iostream>
#include <omp.h>

using namespace std;

int main(){
	int x, y, z;
	#pragma omp parallel for private(x, y) shared(z)
	for(int i = 0; i < 9; i++){
		x = i + 1;
		#pragma omp parallel for private(y) shared(z)
		for(int j = 0; j < 9; j++){
			y = j + 1;
			z = x * y;
			cout << x << "x" << y << "=" << z << endl; 
		}
	}
	return 0;
}