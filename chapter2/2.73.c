#include <stdio.h>
#include <assert.h>

int saturating_add(int x, int y)
{ 
    int s = x + y;
    printf("x=%d\ny=%d\ns=%x\n", x, y,s);
    if (x > 0 && y > 0 && s <= 0)
    {
        return ((unsigned)-1) >> 1;
    }
    if (x < 0 && y < 0 && s >= 0)
    {   
        printf("负溢出：%x", ((unsigned)1 << ((sizeof(int) << 3)  -1)));
        return ((unsigned)1 << ((sizeof(int) << 3)  -1));
    }
    return s;
}

int main()
{
    assert(saturating_add(1, 2) == 3);
    assert(saturating_add(0x7FFFFFFF, 0x7FFFFFFF) == 0x7FFFFFFF);
    assert(saturating_add(0x80000000, 0x80000000) ==  0x80000000);
    return 0;
}