#include <stdio.h>
#include <omp.h>

int main (void){
    int x1=0, x2 = 0, x3 = 0, input, s;

    #pragma omp parallel for
    for(s=0; s<10; s++){
        scanf("%d\n" ,&input);
        #pragma omp critical
        {
            if(x1 < input){
                x3 = x2;
                x2 = x1;
                x1 = input;
            }else{
                if(x2 < input){
                    x3 = x2;
                    x2 = input;
                }else if(x3 < input) x3 = input;
            }
        }
    }
    printf("%d\n%d\n%d\n",x1,x2,x3);
    return(0);
}