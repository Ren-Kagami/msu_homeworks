#include <stdio.h>
#include <stdlib.h>

int c(const void *x,const void *y) {
    return *(int *)x - *(int *)y;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int b[n];
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    qsort(b,n,sizeof(int), c);

    int f = 1;
    for (int i = 0; i < n; i++) {
        if (b[i] != i + 1) {
            f = 0;
            break;
        }
    }
    printf(f ? "Yes" : "No");
    return 0;
}