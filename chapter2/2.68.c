#include <stdio.h>
#include <assert.h>

int lower_bits(int x,int n) {
	int w = sizeof(int)<<3;
	int mark  = (unsigned )-1 >> (w - n);
	return x | mark;
}

int main() {
	assert(lower_bits(0,6) == 0x3f);
	return 0;
}
