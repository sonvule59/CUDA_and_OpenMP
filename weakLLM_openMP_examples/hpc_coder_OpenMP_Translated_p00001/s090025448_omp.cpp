#include<iostream>
#include<algorithm>
#include<omp.h>
using namespace std;
 
const int MAX_N = 9;
int a[MAX_N];
   
int main(){
 
    for(int i=0; i<=MAX_N; i++){
        cin >> a[i];
    }
      
    sort(a, a+10);
    #pragma omp parallel num_threads(4)
    {
        #pragma omp for
        for(int i=0; i<=MAX_N; i++){
            cout << a[i] << endl;
        }
    }
 
    return 0;
}