#include<iostream>
#include<cstdio>
#include<omp.h>

using namespace std;

int main(void)
{
	int ans;
	#pragma omp parallel for
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			ans = i * j;
			printf("%dx%d=%d\n", i, j, ans);
		}
	}
	
	return 0;
}