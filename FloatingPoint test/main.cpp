#include <stdio.h>
#include<cmath>

int main(void) {

    /* float型 4バイト整数型（ int ）double型 8バイト整数( long long ) */
    union { float f; int i; } fValue;
    union { double d;long long i; } dValue;
    double value = 0.1257;

    fValue.f = dValue.d = value;

    printf("%lf\n\n", value);

    printf("float\n");
    /* floatのビットの列を表示します */
    for (int i = 31; i >= 0; i--) {
        if (i == 30 || i == 22) {
            printf(" ");
        }
        printf("%d", (fValue.i >> i) & 1);
    }
    printf("\n");
    /*float 指数部（ 1ビット ）、指数部（ 8ビット ）、仮数部（ 23ビット ） */
    printf("符号部 : %X\n", (fValue.i >> 31) & 1);
    printf("指数部 : %X\n", (fValue.i >> 23) & 0xFF);
    printf("仮数部 : %X\n\n", fValue.i & 0x7FFFFF);


    printf("double\n");
    /* ビットの列を表示します */
    for (int i = 63; i >= 0; i--) {
        if (i == 62 || i == 51) {
            printf(" ");
        }
        printf("%d", (dValue.i >> i) & 1);
    }
    printf("\n");
    /*float 指数部（ 1ビット ）、指数部（ 11ビット ）、仮数部（ 52ビット ） */
    printf("符号部 : %X\n", (dValue.i >> 63) & 1);
    printf("指数部 : %X\n", (dValue.i >> 52) & 0xBFF);
    printf("仮数部 : %X\n", dValue.i & 0xFFFFFFFFFFFFF);

    return 0;
}