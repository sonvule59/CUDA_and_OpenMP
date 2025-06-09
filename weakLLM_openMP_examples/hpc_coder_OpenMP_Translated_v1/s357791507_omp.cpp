#include<iostream>
#include<omp.h>

using namespace std;

int main(){

#pragma omp parallel for
	for(int i1=0 ; i1<9 ; i1++){
		for(int i2=0 ; i2<9 ; i2++){
			cout << i1+1 << 'x' << i2+1 << '=' << (i1+1)*(i2+1) << endl;
		}
	}
return 0;
}