#include <iostream>
#include <omp.h>

using namespace std;

int main(){
	

	

	
	#pragma omp parallel for
	for (int x = 1; x <= 9; x++){
		for (int i = 1; i <= 9; i++){
			cout << x << "x"<< i << "=" << i * x << "\n"; 
		
		}
	}
	
	return (0);
}