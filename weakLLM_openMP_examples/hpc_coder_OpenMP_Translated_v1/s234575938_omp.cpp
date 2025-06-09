#include<iostream>
#include<omp.h>
using namespace std;

int main(){

int a=1;
int b=1;

#pragma omp parallel for
for (a=1;a<=9;a++){

#pragma omp parallel for
for (b=1;b<=9;b++){

cout<<a<<"x"<<b<<"="<<a*b<<"\n";


}

}



    return 0;
}