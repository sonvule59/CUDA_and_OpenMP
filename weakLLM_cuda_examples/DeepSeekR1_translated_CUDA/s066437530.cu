#include <iostream>

int main()
{
    for(uint8_t i=1;i<10;i++)
       for(uint8_t j=1;j<10;j++)
           printf("%ux%u=%u\n",i,j,i*j);
    return 0;
}