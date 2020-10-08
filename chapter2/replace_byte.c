#include <stdio.h>

unsigned replace_byte(unsigned x, unsigned char b, int i) {
	unsigned to_replace = ((unsigned)b)<<i*8;
	return (x & ~(0xFF << i* 8)) | to_replace;
}

int main () {
	printf("%x \n", replace_byte(0x12345678, 0xAB, 2));
	printf("%x \n", replace_byte(0x12345678, 0xAB, 0));
	return 0;
}
