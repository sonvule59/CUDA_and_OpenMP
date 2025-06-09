#include<iostream>
#include<omp.h>
using namespace std;

int main(){
	
	int a,b,c;
	
	#pragma omp parallel for private(a,b,c)
	for (a=1; a<10; a++){
		
		for (b=1; b<10; b++){
			
			c=a*b;
			cout << a <<"x"<< b <<"="<< c <<"\n";
			
		}
	
	}
	
	return 0;
	
}