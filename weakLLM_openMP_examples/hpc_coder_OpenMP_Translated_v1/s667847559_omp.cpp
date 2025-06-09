#include<iostream>
#include<omp.h>
using namespace std;

int printMulti(int i, int j){
    printf("%dx%d=%d\n", i, j, i*j);
}


int main(){
    #pragma omp parallel for collapse(2)
    for (int k=1; k<10; k++){
        for (int l=1; l<10; l++){
            printMulti(k, l);
        }
    }
    return 0;
}