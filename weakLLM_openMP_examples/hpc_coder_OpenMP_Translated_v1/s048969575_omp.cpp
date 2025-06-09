#include <stdio.h>
#include <omp.h>

int main(void){
	#pragma omp parallel for
	FOR(i, 1, 10) FOR(j, 1, 10) printf("%dx%d=%d\n", i, j, i*j);
}