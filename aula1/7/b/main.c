#include <stdio.h>
#include <stdlib.h>

void exit1 (void)
{
  printf("Executing exit handler 1\n");
  exit(1);
}

void exit2 (void)
{
  printf("Executing exit handler 2\n");
  exit(1);
}

int main ()
{
  atexit (exit1);
  atexit (exit2);
  puts ("Main done!");
  abort();
  return 0;
}
