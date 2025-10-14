#include <stdio.h>
#include <math.h>

int main(void) {
  /* tp is for "to print" 
   * ex is end value for x(short for exit) */
  int n, m, x, ex, 
      tp[10001], a[10001];
  scanf("%d", &n);


  for (int i = 0; i <  n; ++i){
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);

  /* processing while asking for x */
  for (int j = 0; j < m; ++j) {  
    scanf("%d", &x);
    for (int i = 0; i < n; ++i) {
      ex += a[i] * pow(x, i);
    }
    tp[10000 - j] = ex;
    ex = 0;
  }
  for (int i = 10000 - m + 1; i
      < 10001; ++i) {
    printf("%d ", tp[i]);
  }

  printf("\n");
  return 0;
}
