#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <omp.h>
using namespace std;

int main() {
    clock_t cTimeStart, cTimeEnd;
    cTimeStart = clock();           // 現在時刻
#pragma omp parallel for
    for(int i=1;i<10;++i){
    	for(int j=1;j<10;++j){
    	    cout<<i<<"x"<<j<<"="<<i*j<<endl;
    	}
    }

    cTimeEnd = clock();           // 現在時刻
//    cout<< "処理時間:" <<(cTimeEnd - cTimeStart)/1000 << "[ms]" << endl;

	return 0;
}