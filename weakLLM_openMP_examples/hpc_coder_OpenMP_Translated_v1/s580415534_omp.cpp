#include <stdio.h>
#include <omp.h>

void rec(int i, int j) 
{
  if (j == 10) return;

  printf("%dx%d=%d\n", i, j, i * j);
  rec(i, j + 1);
}

int main(void)
{
  int n;

  #pragma omp parallel for
  for (n = 1; n < 10; n++) {
    rec(n, 1);
  }

  return (0);
}