#include <stdio.h>
#include <stdlib.h>

/* очередь */
typedef struct n {
    int v;
    struct n *n;
} N;

int main(void) {
    /* первый нечетный, второй четный и последний нечетный эллементы очереди */
    N *o1 = NULL, *e1 = NULL,
            *ot = NULL;
    int x,
            pos = 1,
            first = 1;
    while (scanf("%d", &x) == 1 && x != 0) {
        N *t = malloc(sizeof(N));
        t->v = x;
        t->n = NULL;

        if (pos & 1) {
            /* если первый нечетный запускает нечетную очередь, иначе продолжает */
            if (first) {
                o1 = t;
                ot = t;
            } else {
                ot->n = t;
                ot = t;
            }
            first = 0;
        } else {
            /* запись четной очереди в обратном порядке */
            t->n = e1;
            e1 = t;
        }
        pos++;
    }

    for (N *i = o1; i; i = i->n)
        printf("%d ", i->v);
    for (N *i = e1; i; i = i->n)
        printf("%d ", i->v);

    return 0;
}
