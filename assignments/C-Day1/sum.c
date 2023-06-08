#include <stdio.h>
void sum(int x1, int x2, int *x3);
int main(int argc, char **argv) {
  int a = 10, b = 20, c = 0;
  sum(a,b,&c);
  printf("%d, %d, %d", a, b, c);

  int d = 0;
  for (int i=1; i<10; i++) {
    sum(i, i+1, &d);
    printf("%d, %d, %d\n", i, i+1, d);
 
 }
}

void sum(int x1, int x2, int *x3)
{
  *x3 = x1 + x2;
}
