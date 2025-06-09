#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<omp.h>
using namespace std;

int main() {
	#pragma omp parallel for
	for (int a = 1; a < 10; a++) {
		for (int b = 1; b < 10; b++) {
			printf("%dx%d=%d\n", a, b, a*b);
		}
	}
}