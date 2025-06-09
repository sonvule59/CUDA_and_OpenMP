#include <cstdio>
#include<iostream>
#include <omp.h>
using namespace std;

int main(void){
	
	int ans,i,j;
	
	#pragma omp parallel for private(i,j) shared(ans)
	for(i=1;i<10;i++){
		for(j=1;j<10;j++){
			
			ans=i*j;
			
			cout<<i<<"x"<<j<<"="<<ans<<endl;
			
		}
}
}