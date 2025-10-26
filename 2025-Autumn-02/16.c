#include <stdio.h>

int main(void) {
    long long n;
    long c = 0;
    scanf("%lld", &n);

    if (n > 797161) {
        printf("-1\n");
        return 0;
    }
    while (n > 0) {
        long long r = n % 3;
        if (r == 1) {
            c++;
            n /= 3;
        } else if (r == 2) {
            c++;
            n = n / 3 + 1;
        } else {
            n /= 3;
        }
    }
    printf("%ld\n", c);
    return 0;
}