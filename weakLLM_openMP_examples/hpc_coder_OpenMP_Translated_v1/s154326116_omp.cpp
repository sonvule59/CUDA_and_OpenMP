#include <stdio.h>
#include <omp.h>

void QQ(int a,int b){
	if( a >= 10 ){
		return ;
	}else if( b < 10 ){
		printf("%dx%d=%d\n",a,b,a*b);
		QQ(a,b+1);
	}else{
		QQ(a+1,1);
	}
}

int main(){
	#pragma omp parallel
	{
		QQ(1,1);
	}
}