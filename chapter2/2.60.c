#include <stdio.h> 

int funcA(int x) {
	return 	!(x+ 1);
}

int funcB(int x) {
	return !x;
}

int funcC(int x) {
	return ! ~(x>>(sizeof(int) -1) *8);
}
int funcD(int x) { 
	return !(x & 0xff);
}
