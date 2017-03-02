#include <stdio.h>

int main( int argc, char **argv )
{
  int x;
  int *ptrx;

  x = 4;
  ptrx = &x;

  printf("x = %d\n", x);
  printf("ptrx = &x = %p\n", ptrx);

  return 0;
}

