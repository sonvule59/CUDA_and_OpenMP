#include <bits/stdc++.h>
#define IN(a) scanf("%d",&a);
#define OUT(a) printf(a);
#define REPT(i,n) for (int i=1;i<=(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define BR break;

using namespace std;

int main(){
	
	#pragma omp parallel for collapse(2)
	REPT(i,9)
	{
		REPT(j,9)
		{
			printf("%dx%d=%d\n",i,j,i*j);
		}
	}

	return 0;
 }