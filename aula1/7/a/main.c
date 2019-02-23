#include <stdio.h>
#include <stdlib.h>

void exit1 (void)
{
  printf("Executing exit handler 1\n");
}

void exit2 (void)
{
  printf("Executing exit handler 2\n");
}

int main ()
{
  atexit(exit1);
  atexit(exit2);
  printf("Main done!");
  return 0;
}