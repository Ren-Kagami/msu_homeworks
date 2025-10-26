#include <stdio.h>

/* функция разворота беззнакового инта */
unsigned long rev(unsigned long x) {
    unsigned long r = 0;
    while (x) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

int main(void) {
    unsigned int M, N, cur;
    scanf("%u %u", &M, &N);

    cur = M;

    /* повторяем гипотезу о палиндромах N раз */
    for (unsigned int i = 0; i < N; ++i) {
        cur += rev(cur);
    }
    if (cur == rev(cur)) {
        printf("Yes\n"
               "%u\n", cur);
    } else {
        printf("No\n");
    }
    return 0;
}
