#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if (argc == 3)
  {
    int x1 = atoi(argv[1]);
    int x2 = atoi(argv[2]);

    int a = rand() % x2 + 1;

    clock_t start, end;
    double cpu_time_used;
    struct tms t;
    long ticks;
    start = times(&t);
    ticks = sysconf(_SC_CLK_TCK);
    srand(time(NULL));
    do
    {
      int b = rand() % x1;
      printf("%i\n", b);
      a = rand() % x2 + 1;
    } while (a != x2);
    printf("\nClock ticks per second: %ld\n", ticks);

    end = times(&t); 

    printf("Clock:                %4.2f s\n", (double)(end - start) / ticks);
    printf("User time:            %4.2f s\n", (double)t.tms_utime / ticks);
    printf("System time:          %4.2f s\n", (double)t.tms_stime / ticks);
  }
  else
  {
    printf("Invalid number of arguments");
  }
  return 0;
}