#include<iostream>
#include<omp.h>
using namespace std;
int main(){
	int i,j,s;
	#pragma omp parallel for private(i,j,s)
	for(i=1;i<=9;i++){
		for(j=1;j<=9;j++){
			s=i*j;
			cout<<i<<"x"<<j<<"="<<s<<endl;
		}
	}
	return 0;
}