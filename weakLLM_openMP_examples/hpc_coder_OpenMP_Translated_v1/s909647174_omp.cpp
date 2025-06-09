#include <bits/stdc++.h>
#include <vector>
#include <omp.h>
using namespace std;
int x, y;
int main(){
	#pragma omp parallel for
	for(int x = 1; x <= 9; x++){
		for(int y = 1; y <= 9; y++){
			cout << x << "x" << y << "=" << x*y <<"\n";
		}
	}
	return 0;
}