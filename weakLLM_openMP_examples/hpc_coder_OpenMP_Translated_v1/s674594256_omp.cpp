#include <stdio.h>
#include <omp.h>

int main() {

        int x,y;
        #pragma omp parallel for private(x,y)
        for (x=1;x<10;x++){
                for(y=1;y<10;y++){
                        printf("%dx%d=%d\n",x,y,x*y);
                }
        }

        return 0;
}