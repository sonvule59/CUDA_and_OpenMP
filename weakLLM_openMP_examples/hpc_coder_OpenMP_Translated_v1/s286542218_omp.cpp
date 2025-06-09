#include <iostream>
#include <omp.h>
using namespace std;

int main() {
#pragma omp parallel for
	for(int i=1; i<=9; i++){
		for(int j=1; j<=9; j++){
			int y= i*j;
			cout <<i<<"x"<<j<<"="<<y<<endl;
		}
	}
	return 0;
}