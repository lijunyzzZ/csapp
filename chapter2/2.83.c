#include <stdio.h>
#include <assert.h>

unsigned f2u(float a) {
    return *((unsigned int*)&a);

}
int float_ge(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;
    return sx < sy || 
    (sx == 1 && sy == 1 && ux <= uy) ||
    (sx == 0 && sx == 0 && ux >= uy);
}

int main() {
    assert(float_ge(-1.0f, -1.1f) == 1);
    assert(float_ge(1.0f, 1.0f) == 1);
    assert(float_ge(1.0f, 1.0f) == 1);
    return 0;
}