#include <iostream>
#include <omp.h>

using namespace std;

void tabuada(int valor) {
	#pragma omp parallel for
	for(int index = 1; index < 10; ++index)
		cout << valor << "x" << index << "=" << (valor * index) << endl;	
}

int main() {
	#pragma omp parallel
	{
		#pragma omp single
		for(int index = 1; index < 10; ++index)
			tabuada(index);
	}

	return 0;
}