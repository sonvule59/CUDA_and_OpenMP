#include<iostream>
#include<omp.h>
using namespace std;

int main (){
	int n1,n2;

	#pragma omp parallel for private(n1,n2)
	for (n1=1; n1<=9; n1++){
		for (n2=1; n2<=9; n2++){
			cout << n1 << "x" << n2 << "=" << n1*n2 << "\n";
		}
	}
	return 0;
}