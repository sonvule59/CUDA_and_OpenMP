#include <iostream>
#include <omp.h>
using namespace std;

int main() {
	#pragma omp parallel for
	for (int a=0;a<9;a=a+1){
		for(int b=0;b<9;b=b+1){
			cout<<a+1<<"x"<<b+1<<"="<<(a+1)*(b+1)<<endl;
		}
	}
}