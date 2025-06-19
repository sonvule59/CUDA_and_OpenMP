#include <iostream>

int main(void)
{
  const int minNum = 1;
  const int maxNum = 9;

  for (int i = minNum; i <= maxNum; i++) {
    for (int j = minNum; j <= maxNum; j++) {
      std::cout << i << "x" << j << "=" << i * j << std::endl;
    }
  }

  return 0;
}

// CUDA code:
__exit__(nvl, 0, (void)NULL);