#include<iostream>
#include<omp.h>
using namespace std;

int main(){
	#pragma omp parallel for
	for (int i = 1; i < 9 + 1; i++){
		for (int j = 1; j < 9 + 1; j++){
			cout << i << 'x' << j << '=' << i * j << endl;
		}
	}

	return 0;
}