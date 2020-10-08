#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int signed_high_prod(int x, int y)
{
    int64_t s = x * y;
    return s >> 32;
}

unsigned another_unsigned_high_prod(unsigned x, unsigned y)
{
    uint64_t mul = (uint64_t)x * y;
    return mul >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int xu = x >> 31;
    int yu = y >> 31;
    int high = signed_high_prod(x, y);
    return high +    x * yu + xu * x;
}

int main()
{   
    unsigned x = 0x12345678;
    unsigned y = 0xFFFFFFFF;

    assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
    return 0;
}