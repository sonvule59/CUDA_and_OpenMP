#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <cuda_runtime>

using namespace std;

__global__ void kernel(int x, int y, int z) {
    int i = threadIdx.x;
    int j = threadIdx.y;
    int k = threadIdx.z;
    if (i == 0 && j == 0 && k == 0) {
        z = x * y * z;
    } else if (i == 0 && j == 0 && k != 0) {
        z = x * y * z;
    } else if (i == 0 && j != 0 && k == 0) {
        z = x * y * z;
    } else if (i == 0 && j != 0 && k != 0) {
        z = x * y * z;
    } else if (i == 1 && j == 0 && k == 0) {
        z = x * y * z;
    } else if (i == 1 && j == 0 && k != 0) {
        z = x * y * z;
    } else if (i == 1 && j != 0 && k == 0) {
        z = x * y * z;
    } else if (i == 1 && j != 0 && k != 0) {
        z = x * y * z;
    } else if (i == 2 && j == 0 && k == 0) {
        z = x * y * z;
    } else if (i == 2 && j == 0 && k != 0) {
        z = x * y * z;
    } else if (i == 2 && j != 0 && k == 0) {
        z = x * y * z;
    } else if (i == 2 && j != 0 && k != 0) {
        z = x * y * z;
    } else if (i == 3 && j == 0 && k == 0) {
        z = x * y * z;
    } else if (i == 3 && j == 0 && k != 0) {
        z = x * y * z;
    } else if (i == 3 && j != 0 && k == 0) {
        z = x * y * z;
    }