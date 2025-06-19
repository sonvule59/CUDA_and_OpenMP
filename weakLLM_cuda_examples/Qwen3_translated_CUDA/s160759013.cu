#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <stdio.h>
__global__ void kernel()
{
    int32_t x = threadIdx.x;
    int32_t y = threadIdx.y;
    int32_t z = threadIdx.z;
    int32_t i = blockIdx.x;
    int32_t j = blockIdx.y;
    int32_t k = blockIdx.z;
    int32_t a = blockIdx.x;
    int32_t b = blockIdx.y;
    int32_t c = blockIdx.z;
    int32_t d = threadIdx.x;
    int32_t e = threadIdx.y;
    int32_t f = threadIdx.z;
    int32_t g = threadIdx.x;
    int32_t h = threadIdx.y;
    int32_t l = threadIdx.z;
    int32_t m = threadIdx.x;
    int32_t n = threadIdx.y;
    int32_t p = threadIdx.z;
    int32_t q = threadIdx.x;
    int32_t r = threadIdx.y;
    int32_t s = threadIdx.z;
    int32_t t = threadIdx.x;
    int32_t u = threadIdx.y;
    int32_t v = threadIdx.z;
    int32_t w = threadIdx.x;
    int32_t x1 = threadIdx.x;
    int32_t y1 = threadIdx.y;
    int32_t z1 = threadIdx.z;
    int32_t a1 = threadIdx.x;
    int32_t b1 = threadIdx.y;
    int32_t c1 = threadIdx.z;
    int32_t d1 = threadIdx.x;
    int32_t e1 = threadIdx.y;
    int32_t f1 = threadIdx.z;
    int32_t g1 = threadIdx.x;
    int32_t h1 = threadIdx.y;
    int32_t l1 = threadIdx.z;
    int32_t m1 = threadIdx.x;
    int32_t n1 = threadIdx.y;
    int32_t p1 = threadIdx.z;
    int32_t q1 = threadIdx.x;
    int32_t r1 = threadIdx.y;
    int32_t s1 = threadIdx.z;
    int32_t t1 = threadIdx.x;
    int32_t u1 = threadIdx.y;
    int32_t v1 = threadIdx.z;
    int