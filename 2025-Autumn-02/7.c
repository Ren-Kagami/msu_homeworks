#include <stdio.h>
#include <limits.h>

inline static int search(int n, int s, int a[10001]) {
  for (int i = 0; i < n; ++i) {
    if (s == a[i]) return 1;
  }
  return 0;
}

int main(void) {
  /* ma is for max int in a */
  int n, 
      ma = -INT_MAX,
      a[10001];
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) { 
    scanf("%d", &i[a]);
    ma = (a[i] > ma) ? a[i] : ma;
  }

  if (n == ma) {
    for (int i = 1; i <= n; ++i){
      if (search(n, i, a) == 0) goto wrong;
    }
  }
  else goto wrong;

  printf("Yes\n");
  return 0;
wrong:
  printf("No\n");
  return 0;
}
