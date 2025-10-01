#include <string.h>
#include <stdio.h>
 
#define SIZE    21
 
char target[SIZE] = "a shiny white sphere";
 
int main( void )
{
  char * p = target + 8;  
  char * source = target + 2;
 
  printf( "Before memmove, target is \"%s\"\n", target );
  memmove( p, source, 5 );
  printf( "After memmove, target becomes \"%s\"\n", target );
}
 