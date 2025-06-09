#include<iostream>
#include<omp.h>
const int X99 = 9;
const int Y99 = 9;
int main()
{
#pragma omp parallel for collapse(2)
for(int x=1;x<=X99;x++){
for(int y=1;y<=Y99;y++){
std::cout << x << 'x' << y << '='<< x*y << '\n';
}
}
return 0;
}