#include <stdio.h>
#include <assert.h>

int tsub_ovf(int x, int y)
{
    int s = x - y;
    if (x > 0 && y < 0 && s <= 0)
    {
        return 1;
    }
    if (x < 0 && y > 0 && s >= 0)
    {
        return 1;
    }
    return 0;
}
int main()
{
    assert(tsub_ovf(1, 2) == 0);
    assert(tsub_ovf(0x7FFFFFFF, 0x80000000) == 1);
    assert(tsub_ovf(0x80000000, 0x7FFFFFFF) == 1);
    return 0;
}