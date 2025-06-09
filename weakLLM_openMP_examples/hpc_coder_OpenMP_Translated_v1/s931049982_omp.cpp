#include<stdio.h>
#include<omp.h>
int main(){
int x,y,z;
#pragma omp parallel for private(x,y,z)
for(x=1;x<10;x++){
for(y=1;y<10;y++){
z=x*y;
printf("%dx%d=%d\n",x,y,z);
}
}
return 0;
}