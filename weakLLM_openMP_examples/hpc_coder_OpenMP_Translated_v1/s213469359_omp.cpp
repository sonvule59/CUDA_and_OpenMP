#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES // for C++  
#include <cmath> 
#include <omp.h>
using namespace std;
int main(){
	#pragma omp parallel for
	for(int i=1;i<10;i++){
		for(int l=1;l<10;l++){
			cout<<i<<'x'<<l<<"="<<i*l<<endl;
			
			
			
		}
		
		
		
	}
}