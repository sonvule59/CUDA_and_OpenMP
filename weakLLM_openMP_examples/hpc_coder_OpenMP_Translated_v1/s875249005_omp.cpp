#include <cstdio>
#include <iostream>
#include <omp.h>

int main()
{
    #pragma omp parallel for collapse(2)
    for(int x=1;x<10;++x)
        for(int y=1;y<10;++y)
            printf("%dx%d=%d\n",x,y,x*y);
}