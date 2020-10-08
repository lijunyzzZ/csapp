#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f)
{
   
    unsigned sig = f >> 31;
    unsigned exp = f >> 23;
    unsigned frac = f & 0x7FFFFF;
    unsigned mark =  (exp & 0xFF);
   
    int is_NAN = (mark == 0xFF) && (frac != 0);
      printf("%x\n", is_NAN);
    if (is_NAN)
    {
        return f;
    }
    if (exp < 0) {

        frac = f >> 8>>1
    } else {

    }


}
