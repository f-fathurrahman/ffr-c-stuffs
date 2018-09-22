#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gr.h>

int main()
{
  const int N = 10;
  double *x, *y;
  x = (double*)malloc(N*sizeof(double));
  y = (double*)malloc(N*sizeof(double));
  
  const double XLEFT=0.0, XRIGHT=1.0;
  double dx = (XRIGHT - XLEFT)/(N-1);

  int i;
  for(i = 0; i < N; i++) {
    x[i] = XLEFT + i*dx;
    y[i] = sin(x[i])*cos(x[i]);
  }

  gr_polyline(N, x, y);
  gr_axes(gr_tick(0,1), gr_tick(0,1), 0, 0, 1, 1, -0.01);

  getc(stdin);
  return 0;
}
