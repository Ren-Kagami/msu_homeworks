#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    int n;
    double Ti, Vi,
           v = 0, t = 0,
           s[101], a[101];

    /* input */
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &s[i]);

    for (int i = 0; i < n; i++)
        scanf("%lf", &a[i]);

    /* processing speeds */
    for (int i = 0; i < n; ++i) {
        if (fabs(a[i]) < 1e-9) {
            Ti = s[i] / v;
        } else {
            Vi = sqrt(pow(v, 2) + 2 * a[i] * s[i]);
            Ti = (Vi - v) / a[i];
        }
        t += Ti;
        v += a[i] * Ti;
    }

    printf("%.4f\n", t);
    return 0;
}
