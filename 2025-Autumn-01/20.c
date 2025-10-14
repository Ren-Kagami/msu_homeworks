#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Даны действительные числа a, b, c, d. Выяснить, можно ли в прямоугольник со сторонами a, b целиком поместить прямоугольник со сторонами c, d.
// Формат входных данных: четыре вещественных числа a, b, c и d, разделенные одним или несколькими пробелами или символами перевода строки.
// Числа не превосходят 10000 и записаны не более чем с двумя знаками после десятичной точки.
// Формат выходных данных: выведите слово YES, если второй прямоугольник можно поместить в первый, или слово NO в противном случае.

int fits(double a, double b, double p, double q) {
    double temp;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (p < q) {
        temp = p;
        p = q;
        q = temp;
    }

    // ВОТ ТУТ ОКАЗЫВАЕТСЯ ЕСТЬ НОРМАЛЬНАЯ ФОРМУЛА:
    // https://stackoverflow.com/questions/13784274/detect-if-one-rect-can-be-put-into-another-rect
    return ((p <= a && q <= b) || (p > a && b >= (2*p*q*a + (p*p-q*q)*sqrt(p*p+q*q-a*a)) / (p*p+q*q)));
}

int main(void) {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    if (fits(a, b, c, d) || fits(a, b, d, c)) printf("YES\n");
    else printf("NO\n");
}


// 　　　　　　　　   　∧＿∧　　Someone help me... I'm in a bottomless pit...
//    　　　　　　　 ( ;・ω・)
//    　....::::;;;;/つ　つ;;;;::::.......
//    　　　　　　"""''''''''''"""
//    　　Squish, squish, squish...
//
// 　　　　　　        ∧＿∧　　　　Wow, ah, ahhhhh...
// 　　....::::;;;;( ;・ω・);;;;::::.......
//    　　　　　　"""''''''''''"""
//
//    　　Squish, squish, squish...
//
//    　　　　　　 　 　　　　・・・・・・・・・…
// 　　....::::;;;;;∧＿∧;;;::::.......
//    　　　　　　"""''''''''''"""
