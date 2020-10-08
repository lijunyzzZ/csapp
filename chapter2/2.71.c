#include <stdio.h>
#include <assert.h>

int xbyte(unsigned word, int bytenum) {
    int w = sizeof(unsigned);
    int shift_left = (w  - bytenum -1 )<< 3;
    int shift_right = (w -1 )<< 3;
    return (int) word << shift_left >> shift_right;
}

int main() {
    assert(xbyte(0xABCDEFAB, 0) == 0xFFFFFFAB);
    return 0;
}