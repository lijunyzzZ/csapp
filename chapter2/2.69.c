#include <stdio.h>
#include <assert.h>

unsigned rotate_right(unsigned x, int n) {
	unsigned mark = (unsigned )-1 >> (32 - n);
	unsigned left = x & mark;
	unsigned right = x & ~mark;
	return left << (32 -n) | right >> n;
}

int main () { 
	assert(rotate_right(0x12345678, 4) == 0x81234567);
	return 0;
}

