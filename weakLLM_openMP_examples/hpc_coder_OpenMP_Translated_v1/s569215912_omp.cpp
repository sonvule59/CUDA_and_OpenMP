#include <iostream>
#include <omp.h>
int main(void)
{
#pragma omp parallel for
for(int a = 1; a <= 9; a++){
for(int b = 1; b <= 9; b++){
std::cout << a << 'x' << b << '=' << a*b << std::endl;
}
}
return 0;
}