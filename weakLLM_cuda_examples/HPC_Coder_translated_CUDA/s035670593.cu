#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

__global__ void print_table(string* sv, int size) {
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < size) {
		cout << sv[idx] << endl;
	}
}

int main() {
	vector<string> sv;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			stringstream ss;
			ss << i << 'x' << j << '=' << i * j << '\n';
			string temp = ss.str();
			sv.push_back(temp);
		}
	}

	int size = sv.size();
	string* d_sv;
	cudaMalloc((void**)&d_sv, size * sizeof(string));
	cudaMemcpy(d_sv, sv.data(), size * sizeof(string), cudaMemcpyHostToDevice);

	print_table<<<(size + 255) / 256, 256>>>(d_sv, size);

	cudaFree(d_sv);

	getchar();
}