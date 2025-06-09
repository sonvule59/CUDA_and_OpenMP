#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<omp.h>

int main()
{
	int m, n;
	m = 1;
	n = 1;
	#pragma omp parallel for
	for (m = 1; m <= 9; m++) {
		for (n = 1; n <= 9; n++) {
			printf("%dx%d=%d\n", m, n,  m * n);
		}
	}
    return 0;
}