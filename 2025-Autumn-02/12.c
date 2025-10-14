#include <stdio.h>

int main(void) {
    int total = 0, ok = 1,
        front[8], side[8];

    /* input */
    for (int i = 0; i < 8; i++)
        scanf("%d", &front[i]);

    for (int i = 0; i < 8; i++)
        scanf("%d", &side[i]);

    /* validation of input */
    for (int i = 0; i < 8; ++i) {
        if (front[i] < 0 || front[i] > 100 ||
            side[i] < 0 || side[i] > 100) {
            goto wrong;
        }
    }

    /* consistency check */
    for (int i = 0; i < 8 && ok; ++i) {
        int can = 0;
        for (int j = 0; j < 8; ++j)
            if (side[j] >= front[i]) { can = 1; break; }
        if (!can) ok = 0;
    }

    for (int j = 0; j < 8 && ok; ++j) {
        int can = 0;
        for (int i = 0; i < 8; ++i)
            if (front[i] >= side[j]) { can = 1; break; }
        if (!can) ok = 0;
    }

    if (!ok) {
        goto wrong;
    }

    /* compute max number of cubes */
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            total += front[i] < side[j] ? front[i] : side[j];

    printf("%d\n", total);
    return 0;

wrong:
    printf("-1\n");
    return 0;
}
