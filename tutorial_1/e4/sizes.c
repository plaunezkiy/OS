#include <stdio.h>

#define CHAR (sizeof(char))
#define SHORT (sizeof(short))
#define INT (sizeof(int))
#define LONG (sizeof(long))
#define LONGLONG (sizeof(long long))
#define FLOAT (sizeof(float))
#define DOUBLE (sizeof(double))
#define LONGDOUBLE (sizeof(long double))

int main(int argc, char* argv[]) {
    printf("Basic Types:\n");
    printf("char: %ld bytes\n", CHAR);
    printf("short: %ld bytes\n", SHORT);
    printf("int: %ld bytes\n", INT);
    printf("long: %ld bytes\n", LONG);
    printf("long long: %ld bytes\n", LONGLONG);
    printf("\nFloating Point Types:\n");
    printf("float: %ld bytes\n", FLOAT);
    printf("double: %ld bytes\n", DOUBLE);
    printf("long double: %ld bytes\n", LONGDOUBLE);
    return 0;
}