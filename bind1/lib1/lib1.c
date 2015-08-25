#include "lib1.h"
#include <stdio.h>
#include "string.h"

struct testStruct {
  int i;
  cbFunc fptr;
};

struct testStruct *newTestStruct() {
  struct testStruct *s = malloc( sizeof( struct testStruct ) );
  s->i = 6;
  s->fptr = NULL;
  return s;
}

void freeTestStruct( struct testStruct *_s ) {
  if ( _s == NULL )
    return;

  printf( "Freeing testStruct %p\n", _s );
  free( _s );
}

void setFPTR( struct testStruct *_s, cbFunc _fptr ) {
  _s->fptr = _fptr;
  printf( "New function pointer: %p\n", _fptr );
}
void call( struct testStruct *_s, int _i, int _j ) {
  if ( _s->fptr == NULL ) {
    printf( "ERROR the function pointer is NULL\n" );
    return;
  }
  printf( "Function callback return value: %i\n", _s->fptr( _i, _i + _j ) );
}

void printTestStruct( struct testStruct *_s ) {
  printf( "S       = %p\n", _s );
  printf( "S->i    = %i\n", _s->i );
  printf( "S->fptr = %p\n", _s->fptr );
}

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
