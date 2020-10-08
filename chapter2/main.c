#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main1() {
//    int val = 0x87654321;
//    byte_pointer valp = (byte_pointer) &val;
//    show_bytes(valp, 1);
//    show_bytes(valp, 2);
//    show_bytes(valp, 3);
//
//    const char *s = "abcdef";
//    show_bytes(s, strlen(s));
//    show_int(12345);//0x00003039
    short x = 12345;
    short mx = -x;
    show_bytes((byte_pointer) &x, sizeof(short));
    show_bytes((byte_pointer) &mx, sizeof(short));
    return 0;
}

//2.18
void swap(int *x, int *y) {
    printf("0:%d, %d", *x, *y);
    *y = *x ^ *y;
    printf("1:%d, %d", *x, *y);
    *x = *x ^ *y;
    printf("2:%d, %d", *x, *y);
    *y = *x ^ *y;
    printf("3:%d, %d", *x, *y);
}

void printArr(int a[], int cnt) {
    for (int i = 0; i < cnt; ++i) {
        printf("%d", a[i]);
    }
    printf("\n");
}

void reverse_arr(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first <= last; first++, last--) {
//        printf("%d\n", last);
//        printf("%d\n", first);
        if (first == last) {
            break;

        }
        swap(&a[first], &a[last]);
    }


}

//int main() {
////    int a[4] = {1,2,3,4};
////    reverse_arr(a, 4);
////    printArr(a, 4);
////    printf("\n");
//    int b[5] = {1,2,3,4,5};
////    int x = 2;
////    swap(&x,&x);
////    printf("%d", x);
//    reverse_arr(b, 5);
//    printArr(b,5);
//
//}

//2.13

int bis(int x, int m) {
    return x | m;
}

int bic(int x, int m) {
    return (x | m) ^ m;
}


int bool_or(int x, int y) {
    return bis(x, y);
}

int bool_xor(int x, int y) {
    return bis(bic(x, y), bic(y, x));
}

//int main() {
//    printf("%d\n", bic(5, 6));
//    printf("%d\n", bool_xor(5, 6));
//
//
//}
//2.24
int main224() {
    short int v = -12345;
    unsigned short int uv = (unsigned short) v;
    printf("v = %d, uv = %d", v, uv);
    unsigned int u = 4294967295u;
    int tu = (int) u;
    printf("u = %d, tu = %d", u, tu);
    printf("%d", -1 < 0u);
    printf("\n");
    printf("%d", -2147483647 - 1 == 2147483648u);
    printf("%d", -2147483647 - 1 < 2147483647);
    if ( -2147483647 - 1U < 2147483647) {
        printf("xxxx");
    }
    printf("%d", -2147483647 - 1U < 2147483647);
    printf("%d", -2147483647 - 1 < -2147483647);
    printf("\n %d", -2147483647 - 1U);
    return 0;
}

//222
int main222() {
    short sx = -12345;
    unsigned uy = sx;
    printf("uy = %u\t", uy);
    show_bytes((byte_pointer) &uy, sizeof(unsigned));
    //uy = 4294954951	 c7 cf ff ff
    return 0;
}

int fun1(unsigned word) {
    return (int) ((word << 24) >> 24);
}
int fun2(unsigned word){
    return ((int) word << 24) >> 24;
}
void execFunc(unsigned word) {
    printf("execute fun1 : %x", fun1(word));
    printf("execute fun2 : %x", fun2(word));
    printf("\n");
}
int main223() {
    execFunc(0x00000076u);
    execFunc(0x87654321u);
    execFunc(0x000000c9u);
    execFunc(0xEDCBA987u);
    return 0;
}

int main224_() {
    int x = 53191;
    short sx = (short )x;
    int y = sx;
    printf("x = %d\n sx = %d\n y = %d", x, sx, y);
    return 0;

}
//习题2。25
float sum_arr(float arr[], unsigned len){
    int i ;
    float sum = 0;
    for (i = 0; i <= len -1; i++) {
        sum += arr[i];
    }
    return sum;
}
int main225(){
    float f[2] = {1.0, 2.0};
    float res = sum_arr(f, 0);
    printf("%f", res);
}

//2.26
int strLonger(char *s, char *string){
    printf("%lx\n", strlen(s));
    printf("%lx\n", strlen(string));
    printf("%lx\n", strlen(s) - strlen(string));
    return strlen(s) - strlen(string) > 0;
}

int main226(){
    char *s = "xxxx";
    char *t = "sssss";
    printf("%d", strLonger(s, t));
    return 0;
}

//2.27
int uadd_ok(unsigned x, unsigned y){

    return x + y > x;
}
int main227(){
    unsigned int a = ( 1<<31 )+ 1;
    unsigned int b = a;
    printf("%d\n", a + b);
    printf("%d\n", uadd_ok(a, b));
    printf("%d\n", uadd_ok(12u, 34u));

    return 0;
}

//如果出现溢出符号就会改变
int tadd_ok(int x, int y) {
    if (x > 0 && y > 0 && x + y < 0) {
        return 0;
    }
    if (x < 0 && y < 0 && x + y > 0) {
        return 0;
    }
    return 1;
}

//231
int tadd_ok1(int x, int y){
    int sum = x + y;
    return (sum - x == y) && (sum - y == x);
}
//236
int tmult_ok(int x,int y){
    long long s = x *  y;
    int d =x * y;
    long long b = d;
    return s == b;
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;

    int w = sizeof(int) << 3;
    int mask = (int) -1 << (w - k);// -1 => 1111 1111 1111 1111 1111 1111 1111 1111
    //let mask remain unchanged when the first bit of x is 1, otherwise 0.
    int m = 1 << (w - 1); // 1000 0000 0000 0000 0000 0000 0000 0000
    printf("%x\n", ! (x & m) -1 );
    printf("%x\n", m);
    printf("%x\n", mask);
    printf("%x\n", -1);

    mask &= ! (x & m) - 1;
    // 如果x 是正数，那么x & m的计算结果是 0反过来就是1，1 -1 = 0，mask 计算为 0
    // 如果x 是复数，那么x & m 的计算结果是1，反过来是0。0-1就是 ffffffff,与之前的mask的&就还剩下前面k个1后面w为0
    return xsrl | mask;
}
unsigned srl(unsigned x, int k){
    unsigned xsra = (int) x >> k;
    int size  = sizeof(int) << 3;
    int left =  -1 << (size - k);
    return xsra & ~left;
    //思路是将算术右移的数前面补充的于符号位值一样的变为0
}
int bad_int_size_is_32() {
    unsigned set_msb = ((unsigned ) 1) << 31;
    printf("%x\n", set_msb);
    unsigned beyond_msb = set_msb << 1;
    printf("%x\n", beyond_msb);
    return !beyond_msb;
}
int lower_bits(int x,int n) {
    int w = sizeof(int)<<3;

    int mark  = (unsigned )-1 >> (w - n);
    return x | mark;
}

unsigned rotate_right(unsigned x, int n) {
    unsigned mark = (unsigned )-1 >> (32 - n);

    unsigned left = x & mark;
    unsigned right = x & ~mark;
    printf("%x\n",  right >> n);
    return left << (32 -n) | right >> n;
}
int main() {
//    printf("%x --- %x", sra(-100, 2) , -100>>2 );
   printf("%x", rotate_right(0x12345678,0));
    return 0;
}