#include <cstdio>
#include <omp.h>
#define rep1(i,x) for(int i=1;i<=x;++i)
int main()
{
    #pragma omp parallel for collapse(2)
    rep1(i,9)rep1(j,9)printf("%dx%d=%d\n",i,j,i*j);
}