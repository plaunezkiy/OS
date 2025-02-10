#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int (*func_ptr)(int, int) = 0;

int main() {
    int x = 45, y = 87, z = 135;
    int value;
    if (z <= 128) {
        func_ptr = max;
    } else {
        func_ptr = min;
    }
    value = func_ptr(x, y);
    printf("z = %d, value = %d\n", z, value);
}