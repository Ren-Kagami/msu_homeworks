#include <stdio.h>

int main(void) {
    int n, x, ex = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        ex ^= x;
    }

    printf("%d\n", ex);
    return 0;
}