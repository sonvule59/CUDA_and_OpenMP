#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main()
{
	int i,k;
	int a,b;

	/**--init --**/
	#pragma omp parallel for private(a,b)
	for (a=1,i=1 ; i<10 ; i++,a++) {
		for (b=1,k=1 ; k<10 ; k++,b++) {
			printf("%dx%d=%d\n",a,b,a*b);
		}
	}
	return 0;
}