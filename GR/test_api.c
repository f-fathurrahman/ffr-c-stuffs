#include <stdio.h>
#include <gr.h>

void test_gr_tick()
{
  double dx = gr_tick(0.0, 2.0);
  printf("dx = %18.10f\n", dx);
}

int main()
{
  test_gr_tick();
  return 0;
}
