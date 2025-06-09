#include<stdio.h>
#include<omp.h>
int main(void)
{
	int a,i;
	#pragma omp parallel for private(i)
	for (a = 1; a <= 9; a++) {
		for (i = 1; i <= 9; i++) {
			printf("%dx%d=%d\n",a,i,a*i);
		}
	}
}