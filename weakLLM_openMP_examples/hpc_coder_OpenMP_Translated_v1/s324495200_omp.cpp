#include<stdio.h>
#include<omp.h>
using namespace std;

int main() {
	#pragma omp parallel for
	for (int _____ = 1; _____ <= 9; _____++) {
		for (int ____ = 1; ____ <= 9; ____++) {
			printf("%dx%d=%d\n", _____, ____, _____*____);
		}
	}
}