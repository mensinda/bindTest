#ifndef LIB1_H
#define LIB1_H

#include <stdlib.h>

typedef int *INT_ARRAY;
typedef char const *STRING;

struct testStruct;

typedef int ( *cbFunc )( int, int );

struct testStruct *newTestStruct();
void freeTestStruct( struct testStruct *_s );

void printTestStruct( struct testStruct *_s );

int funcF( int *p, STRING s, int i );
int sumArray( INT_ARRAY p, unsigned int size );
int getSize();
void getString( char *buff );
size_t getString2( char **buff );

#endif /* end of include guard: LIB1_H */
