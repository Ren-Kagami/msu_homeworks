#include <stdio.h>

int main(void) {
    double  Ax, Ay,
            Bx, By,
            Cx, Cy,
            Mx, My;

    scanf("%lf %lf %lf %lf %lf %lf",    &Ax, &Ay,
                                        &Bx, &By,
                                        &Cx, &Cy);

    Mx = (Ax + Bx + Cx) / 3.0;
    My = (Ay + By + Cy) / 3.0;

    printf("%.4f %.4f\n", Mx, My);


    return 0;
}