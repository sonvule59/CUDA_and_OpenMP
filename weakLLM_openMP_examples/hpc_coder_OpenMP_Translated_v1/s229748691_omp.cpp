#include<iostream>
#include<omp.h>

int main(){

	int a=0,i,b;

	#pragma omp parallel for private(i,b) shared(a)
	for(i=1;i<10;i++){
		a=a+1;
		#pragma omp parallel for private(b) shared(a)
		for(b=1;b<10;b++){
			std::cout<<a<<"x"<<b<<"=";
			std::cout<<a*b<<std::endl;
		}
	}
	return 0;
}