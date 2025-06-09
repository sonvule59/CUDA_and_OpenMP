#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include<string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <omp.h>
using namespace std;
typedef vector <int> ivector;

int main(){
	
	#pragma omp parallel for
	for (int i = 1; i <= 9; i++){
		for (int j = 1; j <= 9; j++){
			cout << i << "x" << j <<"="<< i*j << endl;
		}
	}

	return 0;
}