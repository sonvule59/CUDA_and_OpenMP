#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
 
signed main(){
   #pragma omp parallel for
   for(int a=0;a<9;a++){
       for(int b=0;b<9;b++){
	   printf("%dx%d=%d\n",a+1,b+1,(a+1)*(b+1));
	   }
       }
}