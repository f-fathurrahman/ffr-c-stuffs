#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gr.h>

int main()
{
  const double PI = 4.0*atan(1.0);

  const int N = 100;
  
  double *x, *y;
  x = (double*)malloc(N*sizeof(double));
  y = (double*)malloc(N*sizeof(double));
  
  const double XLEFT=0.0, XRIGHT=1.0;
  const double L = XRIGHT - XLEFT;
  const double dx = L/(N-1);

  int i;
  for(i = 0; i < N; i++) {
    x[i] = XLEFT + i*dx;
    y[i] = sin(2*PI*x[i]/L);
  }

  gr_setwindow(0.0, 1.0, -1.0, 1.0);

  gr_setlinewidth(2.0);
  gr_polyline(N, x, y);

  gr_setlinewidth(1.0);
  gr_axes( 0.2, 0.2, 0.0, 0.0, 1, 1, 0.01);

  gr_updatews();

  return 0;
}
