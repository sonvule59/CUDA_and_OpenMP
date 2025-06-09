#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <omp.h>
using namespace std;
int kaijo(int n){
	int ans = 1;
	if (n != 0){
		for (int i = 0; i < n; i++){
			ans *= (n - i);
		}
	}
	else{
		ans = 1;
	}
	return ans;
}

int main(){
	#pragma omp parallel for
	for (int i = 1; i < 10;  i++){
		for (int j = 1; j < 10;  j++){
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}

	return 0;
}