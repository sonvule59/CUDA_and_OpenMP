#include <iostream>
#include <omp.h>

int main()
{
     #pragma omp parallel for collapse(2)
     for(uint8_t i=1;i<10;i++)
          for(uint8_t j=1;j<10;j++)
               printf("%ux%u=%u\n",i,j,i*j);
     return 0;
}

The `#pragma omp parallel for collapse(2)` directive is used to parallelize the nested loops. The `collapse(2)` clause tells OpenMP to collapse the two loops into one, which can improve performance.