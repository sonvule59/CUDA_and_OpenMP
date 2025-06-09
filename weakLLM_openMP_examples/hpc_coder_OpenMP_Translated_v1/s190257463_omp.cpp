#include <stdio.h>
#include <omp.h>

int n; // (0 < n <= 20)
int hx, hy, dx, dy;
int cx[20], cy[20]; // (-1000 <= h, d, c <= 1000)

void init() {
  // 事前処理なし
}

bool input() {
  // 入力なし
  return false;
}

int main() {
  int i, j;

  init();
  while (input()) {
  }

  #pragma omp parallel for
  for (i = 1; i <= 9; i++) {
    for (j = 1; j <= 9; j++) {
      printf("%dx%d=%d\n", i, j, i * j);
    }
  }

  return 0;
}