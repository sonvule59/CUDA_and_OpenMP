#include <iostream>
#include <algorithm>
#include <omp.h>
using namespace std;
 
int main(){
    int i;
    int list[10];
    for(i=0;i<10;i++){
        cin >> list[i];
    }
    sort(list,list+10);
    #pragma omp parallel for
    for(i=0;i<3;i++){
        cout << list[9-i] << endl;
    }
    return 0;
}