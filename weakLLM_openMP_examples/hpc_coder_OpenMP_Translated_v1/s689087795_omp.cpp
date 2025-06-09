#include <stdio.h>
#include <omp.h>

int main(void)
{
	int i , j;
	
	#pragma omp parallel for private(i, j)
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			printf("%dx%d=%d\n", i + 1, j + 1, (i + 1) * (j + 1));
		}
	}
	
	return (0);
}