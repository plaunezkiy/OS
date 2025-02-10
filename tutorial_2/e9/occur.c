#include <stdio.h>

int countChars(const char *str, char c) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

int main() {
    char text[] = "hello world. silly baybee";
    char c = 'a';

    int count = countChars(text, c);
    printf("%c appears %d times.\n", c, count);
}