//FOLHA 2 - p3a.c
//FILE COPY
//USAGE: copy source destination

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(int argc, char **argv)
{
  int fd1, nr, nw;
  unsigned char buffer[BUFFER_SIZE];

  if (argc != 2)
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
  while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0) //reads from source file into buffer
    if ((nw = write(STDOUT_FILENO, buffer, nr)) <= 0 || nw != nr) // writes to dest file and checks if the returns are the same(No errors)
    {
      close(fd1);
      return 4;
    }
  close(fd1);
  return 0;
}
