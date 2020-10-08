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


int main(int argc, char* argv[]) {
  int x = 0x80000007;
  assert(divide_power2(x, 1) == x / 2);
  assert(divide_power2(x, 2) == x / 4);
  return 0;
}