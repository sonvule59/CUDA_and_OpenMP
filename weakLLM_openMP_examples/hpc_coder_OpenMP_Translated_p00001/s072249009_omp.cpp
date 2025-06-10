#include<iostream>
#include<omp.h>

using namespace std;

int main(){
	int f=0,s=0,t=0,num,tmp;
	
	#pragma omp parallel for reduction(max:t)
	for(int i=0;i<10;i++){
		cin>>num;
		if(num>t){
			t=num;
		}
	}
	
	#pragma omp parallel for reduction(max:s)
	for(int i=0;i<10;i++){
		if(t>s){
			tmp=s;
			s=t;
			t=tmp;
		}
	}
	
	#pragma omp parallel for reduction(max:f)
	for(int i=0;i<10;i++){
		if(s>f){
			tmp=f;
			f=s;
			s=tmp;
		}
	}
	
	cout << f << endl << s << endl << t << endl;
	
	return 0;
}