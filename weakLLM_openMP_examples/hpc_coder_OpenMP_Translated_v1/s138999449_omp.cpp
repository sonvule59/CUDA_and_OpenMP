#include<stdio.h>
#include<omp.h>
int main(void)
{
	int a,b,c,x;
	x='x';
	#pragma omp parallel for
	for(a=1;a<=9;a++){
		for(b=1;b<=9;b++){
			c=a*b;
	printf("%dx%d=%d\n",a,b,c);
			}
		}
	return 0;
}