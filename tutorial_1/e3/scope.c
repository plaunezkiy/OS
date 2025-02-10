#include <stdio.h>

int i = 0;

int main(int argc, char *argv[]) {
    int i = 1;
    {
        int i = 2;
        {
            int i = 3;
            printf("innermost = %d\n", i);
        }
        printf("inner block = %d\n", i);
    }
    printf("main function = %d\n", i);
    return 0;
}