#include <iostream>
#include <omp.h>
using namespace std;

int main(){ 
	int array[9][9];
	#pragma omp parallel for collapse(2)
	for(int num1=1;num1<=9;num1++){
		for(int num2=1;num2<=9;num2++){

	cout << num1 << 'x' << num2 << '=' << num1*num2 << endl;
		}
	}
	return 0;
}