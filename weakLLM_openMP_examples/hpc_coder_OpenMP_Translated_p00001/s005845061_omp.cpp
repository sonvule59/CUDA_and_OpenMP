c++
#include <iostream>
#include <stdio.h>
#include <omp.h>
using namespace std;
int main(){
    int fst = 0;
    int snd = 0;
    int thd = 0;
    int tmp=0;
    std::cin >> fst;
    #pragma omp parallel for
    for(int i=0;i<9;i++) {
        tmp = 0;
        std::cin >> tmp;
        #pragma omp critical
        {
            if(fst < tmp) {
                thd = snd;
                snd = fst;
                fst = tmp;
            }else if(tmp > snd){
                thd = snd;
                snd = tmp;
            }else if(tmp > thd){
                thd = tmp;
            }else{}
        }
    }
    printf("%d\n%d\n%d\n",fst,snd,thd);
}