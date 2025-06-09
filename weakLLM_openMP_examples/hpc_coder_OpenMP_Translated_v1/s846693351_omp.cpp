#include<iostream>
#include<algorithm>
#include<omp.h>
using namespace std;
int main(){
	int t=63000;
	#pragma omp parallel for
	for(int i=t;i;i--){
		for(int j=max(i,9);j;j--){
			if(i<10&&j<10)cout<<10-i<<"x"<<10-j<<"="<<(10-i)*(10-j)<<endl;
		}
	}
	return 0;
}