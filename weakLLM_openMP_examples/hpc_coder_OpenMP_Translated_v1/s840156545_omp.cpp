#include<iostream>
#include<omp.h>
using namespace std;
int main(){
	int a,b,c;
	#pragma omp parallel for
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			cout<<i<<"x"<<j<<"="<<i*j<<'\n';
		}
	}
	return 0;
}