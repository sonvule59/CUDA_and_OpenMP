#include <iostream>
#include <omp.h>
using namespace std;
int main(){
int a,b,x;

#pragma omp parallel for
for(int j=1;j<=9;j++){
	a=j;
	for(int i=1;i<=9;i++){
		b=i;
		cout<<a<<"x"<<b<<"="<<a*b<<endl;
		
		}
	    }
}