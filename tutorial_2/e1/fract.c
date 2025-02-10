#include <stdio.h>

struct fraction {
    int num;
    int denom;
}; // don't forget the semicolon!

union ufraction {
    int num;
    int denom;
}; // union shares memory among members

int main() {
    struct fraction f1, f2;
    union ufraction uf1, uf2;
    printf("struct fraction size: %ld, union ufraction size: %ld\n",
    sizeof(f1), sizeof(uf1));
    f1.num = 22;
    f1.denom = 7;
    uf1.num = 22;
    uf1.denom = 7; // overwrites uf1.num
    printf("f1 = %d / %d; uf1 = %d / %d\n",
        f1.num, f1.denom, uf1.num, uf1.denom);
    f2 = f1;
    uf2 = uf1;
    printf("f2 = %d / %d; uf2 = %d / %d\n",
        f2.num, f2.denom, uf2.num, uf2.denom);
    return 0;
}