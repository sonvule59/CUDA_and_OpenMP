#include <cstdio>
#include <iostream>
#include <algorithm>
#include <omp.h>

using namespace std;

int main(){
	int m[10];
	
	for(int i=0; i<10; ++i)
		scanf(" %d", &m[i]);
	
	sort(m, m+10, greater<int>());
	
	#pragma omp parallel for
	for(int i=0; i<3; ++i)
		printf("%d\n", m[i]);
		
	return 0;
}