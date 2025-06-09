#include<iostream>
#include<omp.h>
using namespace std;

int main (){
	int a,b;
	#pragma omp parallel for
	for(a=1;a<=9;a++){
		for(b=1;b<=9;b++)
	cout<<a<<"x"<<b<<"="<<a*b<<endl;
	}
	return 0;
	}