#define PRINTMSG(operand) printf(#operand " = %d\n", operand)

#include <stdio.h>

int main( int argc, char **argv )
{
  int a = 46;
  int a_long_name = 1231;
  float f = 4.1;

  PRINTMSG(a);
  PRINTMSG(a_long_name);
  PRINTMSG(f); // what the macro will print?

  return 0;
}


