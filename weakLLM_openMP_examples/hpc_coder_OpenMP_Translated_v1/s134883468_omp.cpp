#include<iostream>
#include<omp.h>
using namespace std;

int main(){
	#pragma omp parallel for
	for(int index = 1; index <= 9 ; index++){
		for(int jndex = 1 ; jndex <= 9 ; jndex++){
			cout<<index<<"x"<<jndex<<"="<<index*jndex<<endl;
		}
	}
	
}