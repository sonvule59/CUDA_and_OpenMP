#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <omp.h>
using namespace std;
const int M = 100000;
const double pi = 3.141592653589;

int main()
{
	#pragma omp parallel for
	for (int i = 1; i <= 9; i++) {
		for (int k = 1; k <= 9; k++) {
			int qq = i*k;
			printf("%dx%d=%d\n", i, k,qq);
		}
	}
}