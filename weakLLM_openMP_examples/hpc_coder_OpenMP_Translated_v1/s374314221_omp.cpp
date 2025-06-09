#include<cstdio>
#include<omp.h>
main(){
FILE *fp = fopen("test","r");
int tmp=0;
 if (fp != NULL)fscanf(fp,"%d",&tmp);
 //printf("%d",tmp);
 if (tmp == 1124)return 1;
 #pragma omp parallel for
 for(int i=1;i<=9;i++){
   for(int j=1;j<=9;j++){
     printf("%dx%d=%d\n",i,j,i*j);
   }
 }
return 0;
}