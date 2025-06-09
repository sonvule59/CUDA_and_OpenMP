#include<iostream>
#include<omp.h>
using namespace std;

int main(){
int a = 1;int b = 1;int i = 1;int ii = 1;
#pragma omp parallel for
for(ii = 1;ii <= 9;ii++){
	b = 1;
	for(i = 1;i <= 9;i++){
	 	cout << a << "x" << b << "=" << a*b << endl;
	 	b = b+1;
		}
	a = a+1;
	}
    return 0;
}