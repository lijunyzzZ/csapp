#include <stdio.h>
#include <assert.h>

//这里求一个数的1是否为偶数个，想到异或只要偶数个的数字都会为0.
//只需要将给定数字里面的所有的数字异或一遍就行了
//为什么用折半异或
//用b0b1b2b3b4...b31来表示二进制。
//第一次结果c1 c2 c3... c16
//其中c1 = b0 ^ b16, c2 = b1 ^ b17,..., c16 = b15 ^ b31
//第二次结果d1, d2,...,d8;
//d1 = c1 ^ c9 = b0 ^ b16 ^ b15 ^ b31,..
//经过几次连续异或之后最终0位的就是所有位的异或。
int even_ones(int i) {
	i ^= i >>  16;
	i ^= i >>  8;
	i ^= i >>  4;
	i ^= i >>  2;
	i ^= i >>  1;
	return !(i & 0x1);
}

int main () {
	assert(!even_ones(2));
	assert(even_ones(3));
	return 0;
}
