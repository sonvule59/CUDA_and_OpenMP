#include<iostream>
#include<omp.h>
using namespace std;
int main(){
	int x,y,z,w;
	#pragma omp parallel for private(x,y,z,w)
	for (x = 1, z = 1; z <= 9; z++, x++){
		for (y = 1, w = 1; w <= 9; w++, y++){
			cout << x << "x" << y << "=" << x * y << endl;
		}
	}








	return 0;
}