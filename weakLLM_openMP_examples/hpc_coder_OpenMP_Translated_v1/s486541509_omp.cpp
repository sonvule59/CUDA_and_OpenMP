#include<iostream>
#include<omp.h>
using namespace std;
int main(){
int i;
int x;
int y;
#pragma omp parallel for private(x)
for(i=1;i<=9;i++){
for(x=1;x<=9;x++){
y=i*x;
cout<<i<<"x"<<x<<"="<<y<<endl;
}
}
return 0;
}