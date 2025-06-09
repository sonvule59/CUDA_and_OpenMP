#include <bits/stdc++.h>
#define times(i,a) for(int i=0;i<(int)a;i++)
#include <omp.h>
using namespace std;

int main(){
 times(i,9) times(j,9) printf("%dx%d=%d\n",i+1,j+1,(i+1)*(j+1));
 #pragma omp parallel for collapse(2)
 for(int i=0;i<9;i++)
 for(int j=0;j<9;j++)
 printf("%dx%d=%d\n",i+1,j+1,(i+1)*(j+1));
 return 0;
}