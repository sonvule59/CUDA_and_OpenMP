#include<stdio.h>
#include<omp.h>
int main()
{
    int n,p;
    #pragma omp parallel for private(n)
    for(p=1;p<=9;p++)
    {
        for(n=1;n<10;n++)
        {
            printf("%dx%d=%d\n",p,n,p*n);
        }
    }
    return 0;
}