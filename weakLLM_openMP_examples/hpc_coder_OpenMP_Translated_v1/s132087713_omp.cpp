#include <iostream>
#include <omp.h>
int s,e;
int main(){
    #pragma omp parallel
    {
        while(s*e<81)
        {
            #pragma omp critical
            {
                s+=(e=e%9+1)<2;
            }
            std::cout<<s<<'x'<<e<<'='<<s*e<<'\n';
        }
    }
    return 0;
}