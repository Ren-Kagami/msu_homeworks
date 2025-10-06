#include <stdio.h>

int h2i(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return 10 + (c - 'A');
    if (c >= 'a' && c <= 'f')
        return 10 + (c - 'a');
}

int* i2b(int c) {
    int a =
}


int main(void) {
    int a[4];
    int a1,b1,c1,d1;
    char in[4];
    scanf("%s", &in);

    for (int i = 0; i < 4; ++i) {
        a[i] = h2i(in[i]);
    }
    for (int i = 0; i < 4; ++i) {
        printf("%d ", i2b(a[i]));
    }
    return 0;
}