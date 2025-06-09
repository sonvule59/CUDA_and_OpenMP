#include <iostream>
#include <omp.h>
using namespace std;

int main(){
	#pragma omp parallel for
	for (int i = 1; i <= 9; i++){
		for (int n = 1; n <= 9; n++){
			cout << i << "x" << n << "="<<i*n<<endl;
		}
		}

}