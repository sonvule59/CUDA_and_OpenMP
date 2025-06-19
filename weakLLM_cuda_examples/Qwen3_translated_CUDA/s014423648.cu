#include <stdio.h>

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

__global__ int main()
{
  int i, j, k;
  __global__ int *ptr;
  ptr = (int*)malloc(10 * sizeof(int));
  for (i = 0; i < 10; i++) {
    ptr[i] = i;
  }
  for (i = 0; i < 10; i++) {
    ptr[i] = i * i;
  }
  for (i = 0; i < 10; i++) {
    printf("%d\n", ptr[i]);
  }
}

#include <stdio.h>

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

__global__ int main()
{
  int i, j, k;
  __global__ int *ptr;
  ptr = (int*)malloc(10 * sizeof(int));
  for (i = 0; i < 10; i++) {
    ptr[i] = i;
  }
  for (i = 0; i < 10; i++) {
    ptr[i] = i * i;
  }
  for (i = 0; i < 10; i++) {
    printf("%d\n", ptr[i]);
  }
}

#include <stdio.h>

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

__global__ int main()
{
  int i, j, k;
  __global__ int *ptr;
  ptr = (int*)malloc(10 * sizeof(int));
  for (i = 0; i < 10; i++) {
    ptr[i] = i;
  }
  for (i = 0; i < 10; i++) {
    ptr[i] = i * i;
  }
  for (i = 0; i < 10; i++) {
    printf("%d\n", ptr[i]);
  }
}

#include <stdio.h>

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

__global__ int main()
{
  int i,