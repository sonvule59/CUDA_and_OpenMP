#include <omp.h>

int main() {
    int n = 1000000;
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += i;
    }

    printf("Sum: %d\n", sum);

    return 0;
}