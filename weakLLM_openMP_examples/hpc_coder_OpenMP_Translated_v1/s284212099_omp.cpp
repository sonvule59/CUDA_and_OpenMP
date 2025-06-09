#include <iostream>
#include <omp.h>
using namespace std;

int main() {
	
	#pragma omp parallel for
	for(int rows=1;rows<10;rows++){
		
			for(int colm=1;colm<10;colm++){
				cout <<rows <<"x" <<colm<<"="<<rows*colm<<endl;
			}
		}
	
	
	return 0;
}