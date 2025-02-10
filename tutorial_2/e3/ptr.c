#include <stdio.h>

int main() {
    int *p, x;
    p = &x;
    *p = 3;

    printf("&p = %p - &x = %p\n", &p, &x);
    printf("p = %p - x = %d\n", p, x);
    printf("*p = %d\n", *p);

    return 0;
}