#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
  if (argc == 3)
  {
    int x1 = atoi(argv[1]);
    int x2 = atoi(argv[2]);
    
    int a = rand() % x2 + 1;

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    srand(time(NULL));
    do
    {
      int b = rand() % x1;
      printf("%i\n", b);
      a = rand() % x2 + 1;
    } while (a != x2);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  }
  else
  {
    printf("Invalid number of arguments");
  }
  return 0;
}