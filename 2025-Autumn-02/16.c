#include <stdio.h>

/* define is because of segmentation fault
 * when it is static ll or smthng else */
#define M 4000003

/* hash table for nams
 * and table of all nums */
char ht[M];
long long nums[M];

int main(void) {
    int n, j,
        p = 0;
    long long x, t,
              ex[3];
    scanf("%d", &n);

    /* using hash table to count occurrences
     * 1 = appears once, 2 = appears twice */
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        j = (x % M + M) % M;
        while (ht[j] && nums[j] != x)
            j = (j + 1) % M;
        if (!ht[j]) {
            nums[j] = x;
            ht[j] = 1;
        } else
            ht[j] = 2;
    }

    /* getting all nums with hash = 1 */
    for (int i = 0; i < M && p < 3; ++i) {
        if (ht[i] == 1)
            ex[p++] = nums[i];
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (ex[i] > ex[j]) {
                t = ex[i];
                ex[i] = ex[j];
                ex[j] = t;
            }
        }
    }
    printf("%lld %lld %lld\n", ex[0], ex[1], ex[2]);
}

/*
evryone after my code review:
                   　､　　|＼　　,　,i
            　　　|:::ヽ.|::::::VV:V::|
  ヽ､_ト!::::::::::::::::::::::::::::|
　                ヾ:｀::::::t―-=､／ﾑ|
　                 .ヾ::::::∠⌒　　⌒ |､
　　                 ,〉:＞　●　　● !ｊ
　　                 {lﾞzi u 　┌‐┐　 }
　　                    ｀ｰヽ､ ヽ‐' ,／
　　　　                    ∠ﾞミﾆ7￣
　　　                     ./ ／＼｀l
　　　                   l /　 　 「i
　　　                 .| |　　　 l |
　　　                     |　Ｔ'┬-リ
                      |　.|　|　　|
*/
