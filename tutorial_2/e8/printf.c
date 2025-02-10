#include <stdio.h>

int main(){
    printf("Hello %d World %d!\n", 11, 13+4);
    printf("Hello %s World %c%d!\n", "great", 'A', 3);
    printf("number: %4u\n", 15); // width without leading zeros
    printf("number: %04u\n", 15); // width with leading zeros
    printf("number: %.3f\n", 0.123456789f); // float precision
    return 0;
}