#include <stdio.h>

void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 1;
    int b = 2;
    Swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}