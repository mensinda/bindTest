#include <stdlib.h>
#include <stdio.h>
#include "utils/bindings/src/tinycc/libtcc.h"

int add( int a, int b ) { return a + b; }

char my_program[] = "int fib(int n) {\n"
                    "    if (n <= 2) return 1;\n"
                    "    else return fib(n-1) + fib(n-2);\n"
                    "}\n"
                    "int foobar(int n) {\n"
                    "    printf(\"fib(%d) = %d\\n\", n, fib(n));\n"
                    "    printf(\"add(%d, %d) = %d\\n\", n, 2 * n, add(n, 2 * n));\n"
                    "    return 1337;\n"
                    "}\n";

int main( int argc, char **argv ) {
  TCCState *s;
  int ( *foobar_func )( int );
  void *mem;

  s = tcc_new();
  tcc_set_output_type( s, TCC_OUTPUT_MEMORY );
  tcc_add_symbol( s, "add", add );
  tcc_compile_string( s, my_program );

  mem = malloc( tcc_relocate( s, NULL ) );
  tcc_relocate( s, mem );

  foobar_func = tcc_get_symbol( s, "foobar" );

  tcc_delete( s );

  printf( "foobar returned: %d\n", foobar_func( 32 ) );

  free( mem );
  return 0;
}
