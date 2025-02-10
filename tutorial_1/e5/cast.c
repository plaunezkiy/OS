#include <stdio.h>

int main(int argc, char* argv[]) {
    char ch;
    short s;
    s = 321;
    ch = s; // Implicit casting from short to char
    printf("Original short: %hi\n", s);
    printf("After casting to char: %hhi\n", ch);
    printf("After casting back to short: %hi\n", (short)ch);
    return 0;
}
