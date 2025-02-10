#include <stdio.h>
#define ELEMENTS 16

int main() {
    int idx;
    int numbers[ELEMENTS];
    // Populate the array
    for (int i = 0; i < ELEMENTS; i++) {
        numbers[i] = i;
    }
    // Access in-bound
    idx = 1;
    printf("numbers[%d] = %d\n", idx, numbers[idx]);
    // Access out-of-bounds
    idx = ELEMENTS + 4;
    printf("numbers[%d] = %d\n", idx, numbers[idx]);

    return 0;
}