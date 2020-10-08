#include <stdio.h>
typedef unsigned char* byte_pointer;
int is_little_endian(){
	int test_num = 0xff;
	byte_pointer start = (byte_pointer) &test_num;
	return start[0] == 0xff;
}

int replace_byte(int x, int y){
	byte_pointer xc = (byte_pointer)&x;
	byte_pointer yc = (byte_pointer)&y;
	if (is_little_endian()) {
		yc[0] = xc[0];
	} else {
		yc[7] = xc[7];
	}
	return y;
}

int main() {
	printf("%d", is_little_endian());
	int x = 0x89abcdef;
	int y = 0x76543210;
	printf("%x", replace_byte(x, y));
	return 0;
}
