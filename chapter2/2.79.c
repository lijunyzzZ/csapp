#include <stdio.h>
#include <assert.h>
#include <limits.h>

int divide_power2(int x, int k)
{
    int is_neg = x & INT_MIN;
    printf("%d\n", x + (1 << k) - 1);
    (is_neg && (x = x + (1 << k) - 1));
    printf("%d\n", x >> k);
    return x >> k;
}

int fiveeights(int x)
{
    int s = divide_power2(x, 3);
    return (s << 2) + s;
}

int main()
{

    assert(fiveeights(209) == 209 / 8 * 5);
    assert(fiveeights(-209) == -209 / 8 * 5);
    return 0;
}