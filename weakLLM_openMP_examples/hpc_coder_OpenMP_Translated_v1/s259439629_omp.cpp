#include<iostream>
#include<omp.h>
using namespace std;

int main(){
	int index,jndex;
	#pragma omp parallel for private(index,jndex)
	for(index = 1; index <= 9 ; index++){
		for(jndex = 1 ; jndex <= 9 ; jndex++){
			cout<<index<<"x"<<jndex<<"="<<index*jndex<<endl;
		}
	}
	
}