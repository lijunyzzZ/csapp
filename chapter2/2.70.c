#include <stdio.h>
#include <assert.h>

int fits_bits(int x, int n)
{
    int w = sizeof(int) << 3;
    int offset = w - n;
    return (x << offset >> offset) == x;
}

int main()
{
    assert(!fits_bits(0xFF, 8));
    assert(!fits_bits(~0xFF, 8));

    assert(fits_bits(0b0010, 3));
    return 0;
}