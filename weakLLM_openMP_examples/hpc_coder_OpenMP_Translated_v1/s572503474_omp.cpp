#include <iostream>
#include <omp.h>
using namespace std;

int main(){
	#pragma omp parallel for
	for(int i = 0;i < 9;++i){
		for(int j = 0;j < 9;++j){
			cout << i + 1 << 'x' << j + 1 << '=' << (i + 1) * (j + 1) << endl;
		}
	}
	return 0;
}