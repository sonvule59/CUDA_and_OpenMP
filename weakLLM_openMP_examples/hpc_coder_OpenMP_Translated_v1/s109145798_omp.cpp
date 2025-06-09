#include <iostream>
#include <stdio.h>
#include <omp.h>

int i = 1;

int main(){
	#pragma omp parallel for
	for(i = 1; i <= 9; i++){
		for(int r = 1; r <= 9; r++){
			int num = i * r;
			printf("%dx%d=%d\n", i, r, num);
		}
	}
	return 0;
}