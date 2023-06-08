#include <stdio.h>
int main() {
  int x = 15, y;
  int *ptrX = 0;

  ptrX = &x;
  y = *ptrX + x;

  *ptrX = 50;
  printf("\n %d \n", y);
    }
