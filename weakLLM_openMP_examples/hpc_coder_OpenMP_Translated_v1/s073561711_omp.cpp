#include<iostream>
#include<omp.h>
using namespace std;
int main(){
    int i=1,ii=1;
    
    #pragma omp parallel for
    for(i=1;i<=9;i=i+1){
    for(ii=1;ii<=9;ii=ii+1){
            cout<<i<<"x"<<ii<<"="<<i*ii;
            cout<<endl;
    }}
        
    
    
    return 0;
}