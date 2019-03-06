//FOLHA 2 - p2b.c
//FILE COPY
//USAGE: copy source destination

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <sys/times.h>
#define BUFFER_SIZE 512

int main(int argc, char **argv)
{
  int fd1, fd2, nr, nw;
  unsigned char buffer[BUFFER_SIZE];
  clock_t start, end;
  double cpu_time_used;
  struct tms t;
  long ticks;
  start = times(&t);
  ticks = sysconf(_SC_CLK_TCK);
  if (argc < 2)
  {
    printf("Usage: %s <source> <destination>\n", argv[0]);
    return 1;
  }
  fd1 = open(argv[1], O_RDONLY);
  if (fd1 == -1)
  {
    perror(argv[1]);
    return 2;
  }
  if(argc == 3)
  {
    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2(fd2,STDOUT_FILENO);
  }
  if (fd2 == -1)
  {
    perror(argv[2]);
    close(fd1);
    return 3;
  }
  while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0)     //reads from source file into buffer
    if ((nw = write(STDOUT_FILENO, buffer, nr)) <= 0 || nw != nr) // writes to dest file and checks if the returns are the same(No errors)
    {
      perror(argv[2]);
      close(fd1);
      close(fd2);
      return 4;
    }
  
  close(fd1);
  close(fd2);
  int fd3 = open("/dev/tty", O_WRONLY);
  if(fd3 < 0)
  perror("Existe um erro");
  dup2(fd3,STDOUT_FILENO);
  printf("\nClock ticks per second: %ld\n", ticks);
  end = times(&t);
  printf("Clock:                %4.2f s\n", (double)(end - start) / ticks);
  printf("User time:            %4.2f s\n", (double)t.tms_utime / ticks);
  printf("System time:          %4.2f s\n", (double)t.tms_stime / ticks);


  return 0;
}
