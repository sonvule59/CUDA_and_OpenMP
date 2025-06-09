#include<iostream>
#include<omp.h>
using namespace std;

int main(){

#pragma omp parallel for
for(int n=1; n<=9; n++)
 for(int m =1; m<=9; m++)
  cout << n << "x" << m << "=" <<m*n <<endl; 

    return 0;
}