#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}
void show_int(int x){
	show_bytes((byte_pointer)&x, sizeof(int));
}
void show_double(double d) {
	show_bytes((byte_pointer)&d, sizeof(double));
}

void show_long(long long x){
	show_bytes((byte_pointer)&x, sizeof(long long));
}
int main(){
	int x = 12345;
   show_bytes((byte_pointer)&x, sizeof(int));
	int y = 123123;
   show_bytes((byte_pointer)&y, sizeof(int));
	printf("\n");
 show_int(12345);
	double a = 1231231.45;
	show_double(a);
	long long int  c = 1231241234;
	show_long(c);
}
