#include "lib1.h"
#include <stdio.h>
#include "string.h"

int funcF( int *p, STRING s, int i ) {
  printf( "1: %s: %i\n", s, *p );
  *p *= i;
  printf( "2: %s: %i\n", s, *p );
  return *p - 1;
}

int sumArray( INT_ARRAY p, unsigned int size ) {
  int ret = 0;
  for ( int i = 0; i < size; i++ ) {
    ret += *p;
    *p = ret;
    p++;
  }

  printf( "Array sum: %i\n", ret );
  return ret;
}

int getSize() { return 12; }
void getString( char *buff ) { strcpy( buff, "Hello World" ); }
size_t getString2( char **buff ) {
  *buff = malloc( 12 * sizeof( char ) );
  strcpy( *buff, "Hello World" );
  return 12;
}
