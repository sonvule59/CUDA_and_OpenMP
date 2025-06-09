#include<openmp.h>
#include<stdio.h>
int main()
{
    int n,p;
    for(p=1;p<=9;p++) {
    for(n=1;n<10;n++) {
        printf("%dx%d=%d\n",p,n,p*n);
    }
    }
    return 0;
}