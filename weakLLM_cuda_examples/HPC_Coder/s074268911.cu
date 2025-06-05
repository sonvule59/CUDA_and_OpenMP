#include <stdio.h>
__global__ void print_table(int n, int i, int s, int g) {
    printf("%dx%d=%d\n", g,i, g*i);
    if(i==9){
        i=0;
        g++;         
    }
    if(g==10)
        return;
}

int main(){
    int n, i, s, g;
    for(i=1, g=1; i <10;i++){
             print_table<<<1,1>>>(n, i, s, g);
             if(i==9){
             i=0;
             g++;         
             }
             if(g==10)
             break;
             }
    return 0;
    }