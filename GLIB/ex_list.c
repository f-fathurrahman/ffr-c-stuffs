#include <glib.h>
#include <stdio.h>

int main( int argc, char **argv )
{
  double a_double;

  GList* list = NULL;

  list = g_list_append( list, "Hello world GLIB list!" );
  
  g_list_append( list, "This is the second list!");

  g_list_append( list, 32 );

  a_double = 3.2;
  g_list_append( list, *a_double );

  printf("This first item of the list is '%s'\n", g_list_first(list) -> data);

  printf("The last item of the list is %d\n", g_list_last(list) -> data);

  return 0;
}

