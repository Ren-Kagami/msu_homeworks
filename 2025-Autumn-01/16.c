#include <stdio.h>

// На вход программе подаются координаты вершин треугольника.
// Требуется найти координаты точки пересечения медиан данного треугольника. Ответ выводите с точностью до 4 знаков после запятой.

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