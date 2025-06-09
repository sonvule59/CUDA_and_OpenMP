#include<cstdio>
#include<omp.h>
using namespace std;

// ÄAÉæé2iñ
void rec(int depth, int max_depth, int a[], int &cnt) {
  if ( depth == max_depth ) {
    cnt++;
    return;
  }
  
  #pragma omp parallel for
  for(int i = 0; i < 2; i++) {
    a[depth] = i;
    rec(depth + 1, max_depth, a, cnt);    
  }  
}

int main() {  
  int a[128];
  int cnt = 0;
  int max_depth = 25;
  rec(0, max_depth, a, cnt);
  
  for(int a = 1; a <= 9; a++)
    for(int b = 1; b <= 9; b++)
      printf("%dx%d=%d\n", a, b, a * b);
  return 0;
}