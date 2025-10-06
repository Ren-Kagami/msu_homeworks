#include <stdio.h>

int main(void) {
    unsigned int n;
    int k;

    scanf("%u %d", &n, &k);

    printf("%u", n & ((1u << k) - 1u));

    return 0;
}