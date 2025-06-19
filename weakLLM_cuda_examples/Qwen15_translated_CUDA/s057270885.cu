__global__ void solvex(int x, int y) {
    if (x > 9) return; // Check if x is greater than 9 before proceeding with the calculation
    printf("dx%d%d=%d\n", y, x, x * y); // Print the result for x = y + 1
    solvex(x + 1, y); // Call the function recursively on x + 1 and y
}

__global__ void solvey(int y) {
    if (y > 9) return; // Check if y is greater than 9 before proceeding with the calculation
    solvex(1, y); // Call the function recursively on 1 and y
    solvey(y + 1); // Call the function recursively on y + 1 and y
}

int main() {
    solvey(1); // Solve y = 1 first
    return 0;
}