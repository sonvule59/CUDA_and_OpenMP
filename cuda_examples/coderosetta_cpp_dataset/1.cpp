void paddingChar(unsigned char *P, uint64_t dataBlockSize, uint64_t paddingSize) {
    P[dataBlockSize] = 0x80;
    for (int i = 1; i <= paddingSize - 9; i++) {
        P[dataBlockSize + i] = 0x00;
    }
    for (int i = 1; i <= 8; i++) {
        P[dataBlockSize + paddingSize - i] = (unsigned char)((8 * dataBlockSize) >> (i - 1) * 8);
    }
}