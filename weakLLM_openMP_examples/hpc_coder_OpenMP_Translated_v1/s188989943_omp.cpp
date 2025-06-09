#include<iostream>
#include<omp.h>

int main(){
	int a,b;
	#pragma omp parallel for private(a,b)
	for(a=1;a<=9;a++){
		for(b=1;b<=9;b++){
			std::cout<<a<<"x"<<b<<"="<<a*b<<std::endl;
			}
}
    return 0;
}