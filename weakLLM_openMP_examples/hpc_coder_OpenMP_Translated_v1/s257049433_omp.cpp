#include<iostream>
#include<omp.h>
using namespace std;
int main(){
	int x=1,y=1;
	#pragma omp parallel
	{
		while(1){
			#pragma omp critical
			{
				cout << x << "x" << y << "=" << x*y << endl;
			}
			y=y+1;
			if(x==9&&y==10)break;
			else if(y==10){
				y=1;x=x+1;
			}
		}
	}
	
	return 0;
}