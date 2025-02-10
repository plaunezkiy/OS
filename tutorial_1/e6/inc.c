#include <stdio.h>

int main(int argc, char* argv[]) {
    int i = 42;
    int j;
    printf("Initial value - i: %d\n", i);
    j = (i++ + 10); // Postfix increment
    printf("After i++ - i: %d, j: %d\n", i, j);
    j = (++i + 10); // Prefix increment
    printf("After ++i - i: %d, j: %d\n", i, j);
return 0;
}
