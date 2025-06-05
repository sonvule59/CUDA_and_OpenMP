#include<stdio.h>
int main()
{
	int i,k;
	for(i=1;i<10;i++)
		for(k=1;k<10;k++)
			{
				printf("%d*%d=%d\n",i,k,i*k);
			}
}