#include <iostream>
#include <omp.h>
int main(){
	int a,b,c;
	#pragma omp parallel for private(a,b,c)
	for(a=1;a<10;++a){
		for(b=1;b<10;++b){
			c=a*b;
			std::cout<<a<<"x"<<b<<"="<<c<<std::endl;
		}
	}
	return 0;
}