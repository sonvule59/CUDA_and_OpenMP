#include<iostream>
#include<omp.h>
using namespace std;

int main(void){
    int i;
    int j;
    #pragma omp parallel for
    for(i = 1;i < 10;i++){
        for(j = 1;j < 10;j++){
            cout << i << "x" << j << "=" << i*j << endl;
        }
    }
}