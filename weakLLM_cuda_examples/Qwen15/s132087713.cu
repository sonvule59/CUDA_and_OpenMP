__global__ void s_e_kernel(int s, int e) {
    if (s * e < 81) {
        __shared__ int shared_s[e];
        
        // Copy s and e into shared memory
        for (int i = 0; i < e; ++i) {
            shared_s[i] = s;
        }
        
        // Update s based on e
        s += (e = e % 9 + 1);
        
        // Check if s is less than 2
        while (s <= 2) {
            std::cout << s << 'x' << e << '=' << s * e << '\n';
            s += 1;
        }
    }
}

int main() {
    int s = 5, e = 3;
    
    // Allocate memory for shared variables
    __shared__ int shared_s[4];
    
    // Initialize shared variables with initial values
    shared_s[0] = s;
    shared_s[1] = e;
    shared_s[2] = s;
    shared_s[3] = e;

    // Launch kernel on GPU
    s_e_kernel<<<1, 4>>>(shared_s, e);

    // Print results
    for (int i = 0; i < 4; ++i) {
        std::cout << shared_s[i] << ' ';
    }

    return 0;
}