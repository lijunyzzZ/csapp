#include <stdio.h>

int int_shifts_are_logical() {
	int a = -2;
	int b = a >> 1;
	return !(b >> (sizeof(int) * 8 -1));
	
}
