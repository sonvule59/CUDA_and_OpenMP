#include <iostream>
#include <omp.h>
using namespace std;
int main(){
	#pragma omp parallel for
	for (int A=1;A<=9;A++){
		for (int B=1;B<=9;B++){
			cout<<A<<'x'<<B<<'='<<A*B<<endl;
		}
	}
	return 0;
}