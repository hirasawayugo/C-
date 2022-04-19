#include <stdio.h>
#include<cmath>

int main(void) {

    /* float�^ 4�o�C�g�����^�i int �jdouble�^ 8�o�C�g����( long long ) */
    union { float f; int i; } fValue;
    union { double d;long long i; } dValue;
    double value = 0.1257;

    fValue.f = dValue.d = value;

    printf("%lf\n\n", value);

    printf("float\n");
    /* float�̃r�b�g�̗��\�����܂� */
    for (int i = 31; i >= 0; i--) {
        if (i == 30 || i == 22) {
            printf(" ");
        }
        printf("%d", (fValue.i >> i) & 1);
    }
    printf("\n");
    /*float �w�����i 1�r�b�g �j�A�w�����i 8�r�b�g �j�A�������i 23�r�b�g �j */
    printf("������ : %X\n", (fValue.i >> 31) & 1);
    printf("�w���� : %X\n", (fValue.i >> 23) & 0xFF);
    printf("������ : %X\n\n", fValue.i & 0x7FFFFF);


    printf("double\n");
    /* �r�b�g�̗��\�����܂� */
    for (int i = 63; i >= 0; i--) {
        if (i == 62 || i == 51) {
            printf(" ");
        }
        printf("%d", (dValue.i >> i) & 1);
    }
    printf("\n");
    /*float �w�����i 1�r�b�g �j�A�w�����i 11�r�b�g �j�A�������i 52�r�b�g �j */
    printf("������ : %X\n", (dValue.i >> 63) & 1);
    printf("�w���� : %X\n", (dValue.i >> 52) & 0xBFF);
    printf("������ : %X\n", dValue.i & 0xFFFFFFFFFFFFF);

    return 0;
}