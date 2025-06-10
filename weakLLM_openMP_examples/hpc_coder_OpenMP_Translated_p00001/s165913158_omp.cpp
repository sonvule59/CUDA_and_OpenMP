#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include<iomanip>
#include<vector>
#include<cmath>
#include <algorithm>
#include <omp.h>

using namespace std;

int main(){
	int  a[10];
	for (int i = 0; i < 10; i++){
		cin >> a[i];
	}
	sort(a, a + 10);
	reverse(a, a + 10);
	#pragma omp parallel for
	for (int i = 0; i < 3; i++){
		cout << a[i] << endl;
	}
}