#include <stdio.h>


int max(int a, int b) {
  if (a >= b) return a;
  return b;
}


int main(void) {
  int n, temp, view = 0,
      a[10001], b[10001];
  
  // intput 
  scanf("%d", &n);
  
  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    a[i] = temp;
  }
  
  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    b[i] = temp;
  }
  
  // procedure
  for (int i = 0; i < n; ++i) {
    view += max(a[i], b[i]);
  }
  
  // output
  printf("%d\n", view);
  
  return 0;
}
