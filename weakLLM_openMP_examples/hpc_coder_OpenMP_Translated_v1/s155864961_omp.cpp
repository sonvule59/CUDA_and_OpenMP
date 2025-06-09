#include<iostream>
#include<omp.h>
using namespace std;
int main(){
	int a,b;
#pragma omp parallel for private(a,b)
	for(int j = 1; j<10; j++){
		a = j;
		
		for(int i = 1; i<10; i++){
			b = i;
			
			cout << a << "x" << b << "=" << a*b << endl;
			

		}
	}
}