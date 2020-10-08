#include <stdio.h>
int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;

    int w = sizeof(int) << 3;
    int mask = (int) -1 << (w - k);// -1 => 1111 1111 1111 1111 1111 1111 1111 1111
    //let mask remain unchanged when the first bit of x is 1, otherwise 0.
    int m = 1 << (w - 1); // 1000 0000 0000 0000 0000 0000 0000 0000
    printf("%x\n", ! (x & m) -1 );
    printf("%x\n", m);
    printf("%x\n", mask);
    printf("%x\n", -1);

    mask &= ! (x & m) - 1;
    // 如果x 是正数，那么x & m的计算结果是 0反过来就是1，1 -1 = 0，mask 计算为 0
    // 如果x 是复数，那么x & m 的计算结果是1，反过来是0。0-1就是 ffffffff,与之前的mask的&就还剩下前面k个1后面w为0
    return xsrl | mask;
}
unsigned srl(unsigned x, int k){
    unsigned xsra = (int) x >> k;
    int size  = sizeof(int) << 3;
    int left =  -1 << (size - k);
    return xsra & ~left;
    //思路是将算术右移的数前面补充的于符号位值一样的变为0
}

int main() {
    printf("%x --- %x", sra(-100, 2) , -100>>2 );
    return 0;
}