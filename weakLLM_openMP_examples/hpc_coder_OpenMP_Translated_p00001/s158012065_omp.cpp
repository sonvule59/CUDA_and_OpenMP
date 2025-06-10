#include<stdio.h>
#include<omp.h>
int height[10002];
int main(void){
    int h;
    #pragma omp parallel for
    for(int i = 0;i < 10;i++){
        scanf("%d",&h);
        height[h]++;
    }
    int cnt = 0;
    #pragma omp parallel for
    for(int i = 10000;i >= 0;i--){
        if(height[i] > 0){
            printf("%d\n",i);
            height[i]--;
            #pragma omp atomic
            cnt++;
            if(cnt >= 3) break;
        }
    }
    return 0;
}