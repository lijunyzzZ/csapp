#include <stdio.h>
#include <assert.h>

int any_even_one(unsigned x) { 
	return x | 0;
}

int main () {
	assert(!any_even_one(0));
	assert(any_even_one(1));

	return 0;
}
