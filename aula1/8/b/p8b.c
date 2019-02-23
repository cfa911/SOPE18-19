#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, int **argv)
{
  if (argc == 3)
  {
    char *val1 = argv[1];
    char *val2 = argv[2];
    int x1 = atoi(val1);
    int x2 = atoi(val2);
    srand(time(NULL));
    int a = rand() % x2 + 1;

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    

    do
    {
      srand(time(NULL));
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