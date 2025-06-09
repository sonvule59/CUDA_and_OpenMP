#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    #pragma omp parallel for
    for( int i = 0; i < 9; i++ ){
        for( int j = 0; j < 9; j++ ){
             printf("%dx%d=%d\n", i+1, j+1, (i+1) * (j+1) );
        }
    }
    return 0;
}