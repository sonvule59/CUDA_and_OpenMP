#include<stdio.h>
#include<omp.h>
int main(void){

  int i;
  #pragma omp parallel for
  for(i=1;i<10;i++){
    printf("%dx1=%d\n",i,i*1);
    printf("%dx2=%d\n",i,i*2);
    printf("%dx3=%d\n",i,i*3);
    printf("%dx4=%d\n",i,i*4);
    printf("%dx5=%d\n",i,i*5);
    printf("%dx6=%d\n",i,i*6);
    printf("%dx7=%d\n",i,i*7);
    printf("%dx8=%d\n",i,i*8);
    printf("%dx9=%d\n",i,i*9);

  }


  return 0;
}