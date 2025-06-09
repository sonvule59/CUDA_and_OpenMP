#include <iostream>
#include <omp.h>
int main(){
    #pragma omp parallel for
    for(int s=1;s<10;s++)for(int e=1;e<10;e++)std::cout<<s<<'x'<<e<<'='<<(s*e)<<std::endl;
    return 0;
}