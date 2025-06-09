#include <stdio.h>
#include <omp.h>

#define REP(i,n) for(int i=0;i<n;++i)

int main()
{
  REP(i,10) {
    REP(j,10) {
      printf("%dx%d=%d\n",i,j,i*j);
    }
  }
  return 0;
}


The OpenMP version uses the `#pragma omp parallel for` directive to parallelize the outer loop. The `#pragma omp parallel for` directive creates a team of threads and distributes the iterations of the loop among them. The `#pragma omp parallel for` directive is used to parallelize the loops in the following cases:

- The loop has a `for` or `do-while` loop construct.
- The loop has a `parallel` region.
- The loop has a `parallel` region with a `for` or `do-while` loop construct.
- The loop has a `parallel` region with a `for` or `do-while` loop construct and a `schedule` clause.
- The loop has a `parallel` region with a `for` or `do-while` loop construct and a `schedule` clause and a `collapse` clause.

The `#pragma omp parallel for` directive is used to parallelize the loops in the following cases:

- The loop has a `for` or `do-while` loop construct.
- The loop has a `parallel` region.
- The loop has a `parallel` region with a `for` or `do-while` loop construct.
- The loop has a `parallel` region with a `for` or `do-while` loop construct and a `schedule` clause.
- The loop has a `parallel` region with a `for` or `do-while` loop construct and a `schedule` clause and a `collapse` clause.