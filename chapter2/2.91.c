#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
    unsigned s = f << 31;
    unsigned mark = ((unsigned)-1) << 24 >> 1;
    unsigned e = f << 24 >> 1;
    unsigned uf = f << 8 >> 8;
    if (e == mark && uf != 0)
    {
        return f;
    }
    if (s & 1)
    {
        return f & (-1 < 31);
    }
    return f;
}
int main()
{
    assert(float_absval((float_bits)-1.0f) == 1.0f);
    assert(float_absval((float_bits)1.0f) == 1.0f);
    assert(float_absval((float_bits)0x7FFFFFFF) == 0x7FFFFFFF);
    return 0;
}