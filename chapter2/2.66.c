#include <stdio.h> 
#include <assert.h>

// 这里第一步使用或来将所有FF00变成FFFF就是第一个有效的1重复到后面去生成形如11111，
// （x & 1）在 x = 0时，为0 ，计算出来为 0， x 不为0的时候，先移位生成 FFF111,加一个1，那么就能得到8000
int  leftmost_one(unsigned x) { 
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return (x >> 1) + (x & 1);
}

int main () {
	assert(leftmost_one((unsigned) 3) == 2);

	return 0;
}
