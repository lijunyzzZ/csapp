#include <stdio.h>
#include <assert.h>

int funcA(int x, int y)
{
    return (x > y) == (-x < -y);
}
int funcB(int x, int y)
{
    return ((x + y) << 5) + x - y == 31 * x + 32 * y;
}

int funcC(int x, int y)
{
    return (~x) + ~y == ~(x + y);
}

int funcD(int x, int y)
{
    unsigned ux = (unsigned)x;
    unsigned uy = (unsigned)y;
    printf("%x\n", (int)(ux - uy));
    printf("%x\n",  -(y - x));
    return (int)(ux - uy) == -(y - x);
}

int funcE(int x) {
    return ((x >> 1) << 1) <=x;
} 
int main()
{
    assert(funcA(-1, 0x80000000) == 0);
    assert(funcB(0x7FFFFFFF, 0x7FFFFFFF) == 0);
    assert(funcC(0x7FFFFFFF, 0x7FFFFFFF) == 0);
     assert(funcE(1) == 1);
     assert(funcE(0x7FFFFFFF) == 1);
     assert(funcE(0x80000000) == 1);
    assert(funcD(0x80000000, 0x7FFFFFFF) ==1);
    return 0;
}