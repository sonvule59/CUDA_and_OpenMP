#include<stdio.h>
#include<omp.h>

int main()
{
int x,t1,t2,t3;
t1=0;t2=0;t3=0;
#pragma omp parallel for
for(int i=0;i<10;i++){
scanf("%d",&x);
#pragma omp critical
{
if(x>t1){t3=t2;t2=t1;t1=x;}
else if(x>t2){t3=t2;t2=x;}
else if(x>t3)t3=x;
}
}
printf("%d\n%d\n%d\n",t1,t2,t3);

return 0;
}