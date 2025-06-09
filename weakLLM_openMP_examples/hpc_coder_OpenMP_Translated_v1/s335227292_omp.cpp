#include<iostream>
#include<omp.h>
int main(void){
int i=1,j=1;
#pragma omp parallel for
for(i=1;i<10;i++){
for(j=1;j<10;j++){
std::cout<<i<<"x"<<j<<"="<<i*j<<std::endl;
}}

return 0;
}