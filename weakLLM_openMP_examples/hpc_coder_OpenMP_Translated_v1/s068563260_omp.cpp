#include <iostream>
#include <string>
#include <omp.h>
using namespace std;
 
int main(){
int a=1,b=1,c;
#pragma omp parallel for private(b)
	for(a=1; a<=9; a++){
		for(b=1; b<=9; b++){
   	 	c = a*b;
    	cout<<a<<"x"<<b<<"="<<c<<endl;	
		}
	}
}