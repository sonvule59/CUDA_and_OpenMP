#include <iostream>
#include <omp.h>
int s,e;int main(){
    #pragma omp parallel for
    for(int i=0;i<10;i++){
        s+=(e=e%9+1)<2?s+=e:s;
        std::cout<<s<<'x'<<e<<'='<<s*e<<'\n';
    }
    return 0;
}