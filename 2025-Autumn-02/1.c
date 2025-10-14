#include <stdio.h>

int main(void) {
  int a[10001], cur, i = 0;

  scanf("%d", &cur);
  while (cur != 0)  {
    a[i] = cur;
    ++i;
    scanf("%d", &cur);
  }
  --i;
  for (int j = i; j >= 0; --j) {
    printf("%d ", a[j]);
  }
  printf("\n");
  return 0;
}
