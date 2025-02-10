#include <stdio.h>

int fun(int a, int b);

int main(int argc, char *argv[]) {
    int a = fun(123, 456);
    printf("The result is %d\n", a);
    return 0;
}