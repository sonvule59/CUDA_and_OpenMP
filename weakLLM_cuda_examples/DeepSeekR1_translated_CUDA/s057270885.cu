#include <cstdio>

__cu__void solvex(int x, int y){
    if(x > 9) return ;
    printf("%dx%d=%d\n",y,x,x*y);
    solvex(x+1,y);
}

__cu__void solvey(int y){
    if(y > 9) return ;
    solvex(1, y);
    solvey(y+1);
}

__cu__int main(){
    solvex(1,1);
    return 0;
}