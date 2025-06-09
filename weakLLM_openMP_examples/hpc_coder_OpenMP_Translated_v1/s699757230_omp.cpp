#include <iostream>
#include <omp.h>
using namespace std;

int f(int x, int y){
	cout << x << "x" << y << "=" << x*y << endl;
	return 0;
}

int main(){
	int i;
	int j;
	#pragma omp parallel for
	for(i = 1; i < 10; i++){
		for(j = 1; j < 10; j++){
			f(i, j);
		}
	}
	return 0;
}