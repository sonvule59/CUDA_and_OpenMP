#include<iostream>
#include<omp.h>

using namespace std;

int main(){
    int a=-1,b=-1,c=-1,moun;
    #pragma omp parallel for
    for(int i=0;i<10;i++){
        cin>>moun;
        #pragma omp critical
        {
            if(moun>a){
                c=b;
                b=a;
                a=moun;
            }else if(moun>b){
                c=b;
                b=moun;
            }else if(moun>c)
                c=moun;
        }
    }
    cout<<a<<endl<<b<<endl<<c<<endl;
    return 0;
}