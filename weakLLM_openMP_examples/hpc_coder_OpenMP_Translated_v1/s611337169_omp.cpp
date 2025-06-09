#include<stdio.h>
#include<omp.h>

int main(void) {

#pragma omp parallel for
	for (int i = 1; i <= 9; i++)
	{
		for (int t = 1; t <= 9; t++)
		{
			printf("%dx%d=%d\n", i, t, i*t);
		}
	}
	return 0;
}