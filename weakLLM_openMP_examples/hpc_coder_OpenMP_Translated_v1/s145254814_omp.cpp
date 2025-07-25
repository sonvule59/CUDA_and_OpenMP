#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
	int i, j;
	#pragma omp parallel for private(i, j)
	for(i=1;i<10;i++) {
		for(j=1;j<10;j++) {
			printf("%dx%d=%d\n", i, j, i*j);
		}
	}
	return 0;
}