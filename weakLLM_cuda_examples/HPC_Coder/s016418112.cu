#include<stdio.h>
__global__ void print_table(int p, int n)
{
    printf("%dx%d=%d\n",p,n,p*n);
}
int main()
{
    int p,n;
    for(p=1;p<=9;p++)
    {
    for(n=1;n<10;n++)
    {
        print_table<<<1,1>>>(p,n);
    }
    }
    return 0;
}