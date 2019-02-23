#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, int **argv)
{
  if (argc == 3)
  {
    time_t t;
    char *val1 = argv[1];
    char *val2 = argv[2];
    int x1 = atoi(val1);
    int x2 = atoi(val2);
    srand (time(&t));
    int a = rand()%x2 + 1;
    do
    {
      sleep(1);
      srand(time(&t));
      int b = rand()%x1;
      printf("%i\n",b);
      a = rand()%x2 + 1;
    }while(a != x2);
  }
  else
  {
    printf("Invalid number of arguments");
  }
  return 0;
}