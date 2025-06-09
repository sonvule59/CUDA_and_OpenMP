#include<iostream>
#include<omp.h>
using namespace std;

int main(){

	int f, s;
	#pragma omp parallel for private(f, s)
	for (f = 1; f<10; f++){
		for (s = 1; s<10; s++){
			cout << f << "x" << s << "=" << f*s << endl;
		}
	}
	return 0;
}