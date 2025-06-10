#include <stdio.h>
#include <omp.h>

int main(){
	int a,b[3]={0,0,0};
	#pragma omp parallel for
	for(int i=0;i<10;i++){
		scanf("%d",&a);
		#pragma omp critical
		{
			if(a>=b[2]){
				if(a>=b[1]){
					if(a>=b[0]){
						b[2]=b[1];
						b[1]=b[0];
						b[0]=a;
					}else{
						b[2]=b[1];
						b[1]=a;
					}
				}else{
					b[2]=a;
				}
			}
		}
	}
	for(int i=0;i<3;i++){
		printf("%d\n",b[i]);
	}
}