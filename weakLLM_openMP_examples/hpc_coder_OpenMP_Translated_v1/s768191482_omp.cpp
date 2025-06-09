#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

int i=1,j;
int main(){
	#pragma omp parallel
	{
		#pragma omp for
		for(j=1;j<=10;j++){
			if(++i==10) return 0;
			j=1;
		}
		cout<<i<<"x"<<j<<"="<<i*j<<endl;
	}
}