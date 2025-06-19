#include <stdio.h>
void __QQ(int a, int b) {
    if (a >= 10) {
        return;
    } else if (b < 10) {
        printf("%dx%d=%d\n", a, b, a * b);
        __QQ(a, b + 1);
    } else {
        __QQ(a + 1, 1);
    }
}