#include <stdio.h>
#include <stdlib.h>

struct MyStruct {
  int N;
  double *data;
};

typedef struct MyStruct* hMyStruct;

void init_MyStruct( struct MyStruct *a, int N )
{
  (*a).N = N;
  
  (*a).data = malloc( N*sizeof(double) );
  int i;
  for( i = 0; i < N; i++ ) {
    (*a).data[i] = 1.2;
  }
  printf("Pass here\n");
}

void modify_MyStruct( hMyStruct a )
{
  (*a).data[0] = 3.0;
}

void info_MyStruct( struct MyStruct a )
{
  printf("N = %d\n", a.N );
  int i;
  for( i = 0; i < a.N; i++ ) {
    printf("a[%d] = %f\n", i, a.data[i]);
  }
}

int main()
{
  printf("Hello from ffr\n");
  struct MyStruct a;

  init_MyStruct(&a,3);
  info_MyStruct(a);

  modify_MyStruct(&a);
  info_MyStruct(a);

  return 0;
}
