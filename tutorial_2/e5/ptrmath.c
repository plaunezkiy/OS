#include <stdio.h>

int main() {
    int a, b, *p, *q;
    a = 10;
    b = 20;
    p = &a;
    q = &b;

    *q = a + b;
    // a=10 b=30, p=&a, q=&b
    a = a + *q;
    // a=40 b=30, p=&a, q=&b
    q = p;
    // a=40 b=30, p=&a, q=&a
    *q = a + b;
    // a=70 b=30, p=&a, q=&a

    printf("a = %d, b = %d, *p = %d, *q = %d\n", a, b, *p, *q);
}