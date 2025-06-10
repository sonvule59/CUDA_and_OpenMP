#include <stdio.h>
#include <omp.h>

#define MAX_NUM	(10)

static void 
sort(int h[])
{
	#pragma omp parallel for
	for (int i = 0; i < MAX_NUM; i++) {
		for (int j = MAX_NUM - 1; j > i; j--) {
			if (h[j] > h[j-1]) {
				int tmp = h[j];
				h[j] = h[j-1];
				h[j-1] = tmp;
			}
		}
	}
}

int
main(void)
{
	char line[80];
	int h[MAX_NUM] = { 0 };

 	for (int i = 0 ; i < 10; i++) {
		if (gets(line)) {
			if (sscanf(line, "%d", &(h[i])) != 1) {
				break;
			}
		}
 	}

	sort(h);
	
 	for (int i = 0 ; i < 3; i++) {
 		printf("%d\n", h[i]);
 	}

	return 0;
}