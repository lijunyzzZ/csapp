#include <stdio.h>
#include <assert.h>
#include <limits.h>

int divide_power2(int x, int k) {
  int is_neg = x & INT_MIN;
  printf("%d\n",  x + (1 << k) - 1);
  (is_neg && (x = x + (1 << k) - 1));
  printf("%d\n",  x >> k);
  return x >> k;
}

int mul5div8(int x) {
    int mul5 = (x << 2 )+ x;

    return divide_power2(mul5, 3);
}


int main(int argc, char* argv[]) {
  int x = 0x80000007;
  assert(mul5div8(209) == 209 * 5 / 8);
  assert(mul5div8(-209) == -209 * 5 / 8);
  return 0;
}