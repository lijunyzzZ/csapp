#include <stdio.h>
#include <assert.h>
#include <limits.h>

int funcA(int n) {
    return -1 << n;
}

int funcB(int m, int n) {
    return -1 << (n+ m) >>n ;
}
int main()
{
    unsigned x = 1;
    unsigned y = 2;
    printf("%x\n", -x > -y );

    return 0;
}