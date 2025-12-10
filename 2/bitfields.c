#include <stdio.h>

int main(void) {
    unsigned char a = 0b11100110;
    printf("%d\n", a);

    signed char b = 0b11100110;
    printf("%d\n", b);

    unsigned char h = 0xE6;
    printf("%d\n", h);

    signed char g = 0xE6;
    printf("%d\n", g);
    return 0;
}
