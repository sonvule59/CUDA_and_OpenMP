#include <stdio.h>
#include <omp.h>

int main()
{
	#pragma omp parallel for
	for (int a = 1; a < 10; a++)
	{
		for (int b = 1; b < 10; b++)
		{
			int total;
			total = a * b;
			printf("%dx%d=%d\n", a, b, total);
		}
	}
	return 0;
}