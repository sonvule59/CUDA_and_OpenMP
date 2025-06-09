#include<stdio.h>
#include<omp.h>

int main() {
	int i = 8;
	#pragma omp parallel for
	for (i = 8; i < 89; i++) {
		printf("%dx%d=%d\n", i / 9, i % 9 + 1, i / 9 * (i % 9 + 1));
	}
	return 0;
}