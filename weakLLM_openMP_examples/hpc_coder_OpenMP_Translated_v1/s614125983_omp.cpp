#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<omp.h>
using namespace std;
int main() {
	int n, i, j, h = 0, cnt = 0, m, p, k = 3, l[10], S, L, s[10], a[10];
	#pragma omp parallel for
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			int seki = i*j;
			printf("%dx%d=%d\n", i, j, seki);
		}
	}

}