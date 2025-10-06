#include <stdio.h>

int MAXINT = 1000000;

int main(void) {
    int n, ma = -2147483648, c = 0, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);

        if (temp > ma) {
            ma = temp;
            c = 1;
        }
        else if (temp == ma) {
            ++c;
        }

    }
    printf("%d\n", c);
    return 0;
}