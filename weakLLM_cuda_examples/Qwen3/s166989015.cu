#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <functional>

__global__ void kernel(int *a, int *b, int *c) {
    int i = threadIdx.x;
    int j = threadIdx.y;
    int k = threadIdx.z;
    int x = a[i * 3 + j * 3 + k * 3];
    int y = b[i * 3 + j * 3 + k * 3];
    int z = c[i * 3 + j * 3 + k * 3];
    int x1 = a[i * 3 + j * 3 + k * 3];
    int y1 = b[i * 3 + j * 3 + k * 3];
    int z1 = c[i * 3 + j * 3 + k * 3];
    int x2 = a[i * 3 + j * 3 + k * 3];
    int y2 = b[i * 3 + j * 3 + k * 3];
    int z2 = c[i * 3 + j * 3 + k * 3];
    int x3 = a[i * 3 + j * 3 + k * 3];
    int y3 = b[i * 3 + j * 3 + k * 3];
    int z3 = c[i * 3 + j * 3 + k * 3];
    int x4 = a[i * 3 + j * 3 + k * 3];
    int y4 = b[i * 3 + j * 3 + k * 3];
    int z4 = c[i * 3 + j * 3 + k * 3];
    int x5 = a[i * 3 + j * 3 + k * 3];
    int y5 = b[i * 3 + j * 3 + k * 3];
    int z5 = c[i * 3 + j * 3 + k * 3];
    int x6 = a[i * 3 + j * 3 + k * 3];
    int y6