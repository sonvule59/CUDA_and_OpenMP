#include<iostream>
#include<omp.h>
using namespace std;

int main(){
		
	#pragma omp parallel for
	for(int i=1; i<=9; i++){
		cout << "1x" << i << "=" << i << endl;
	}
	#pragma omp parallel for
	for(int i=1; i<=9; i++){
		cout << "2x" << i << "=" << 2*i << endl;
	}
	#pragma omp parallel for
	for(int i=1; i<=9; i++){
		cout << "3x" << i << "=" << 3*i << endl;
	}
	#pragma omp parallel for
	for(int i=1; i<=9; i++){
		cout << "4x" << i << "=" << 4*i << endl;
	}
	#pragma omp parallel for
	for(int i=1; i<=9; i++){
		cout << "5x" << i << "=" << 5*i << endl;
	}
	#pragma omp parallel for
	for(int i=1; i<=9; i++){
		cout << "6x" << i << "=" << 6*i << endl;
	}
	#pragma omp parallel for
	for(int i=1; i<=9; i++){
		cout << "7x" << i << "=" << 7*i << endl;
	}
	#pragma omp parallel for
	for(int i=1; i<=9; i++){
		cout << "8x" << i << "=" << 8*i << endl;
	}
	#pragma omp parallel for
	for(int i=1; i<=9; i++){
		cout << "9x" << i << "=" << 9*i << endl;
	}
	
	return 0;
}