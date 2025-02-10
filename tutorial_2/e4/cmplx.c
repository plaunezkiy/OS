#include <stdio.h>

struct complex {
    double real;
    double imag;
};

typedef struct complex Complex;

#define ELEMENTS 4

int main() {
    Complex cmplx[ELEMENTS];
    Complex sum = {0, 0};

    for (int i = 0; i < ELEMENTS; i++) {
        cmplx[i].real = i;
        cmplx[i].imag = i * 2;
    }

    for (int i = 0; i < ELEMENTS; i++) {
        sum.real += cmplx[i].real;
        sum.imag += cmplx[i].imag;
    }

    printf("Sum: %lf + %lfi\n", sum.real, sum.imag);

    return 0;
}