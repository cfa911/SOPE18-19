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
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 512

int main(int argc, char **argv)
{
    int fd1, i = 0;
    char chr,temp[BUFFER_SIZE];
    unsigned char buffer[BUFFER_SIZE];

    if (argc < 2)
    {
        printf("Usage: %s <source> \n", argv[0]);
        return 1;
    }
    fd1 = open(argv[1], O_CREAT | O_RDWR  | O_APPEND);
    if (fd1 == -1)
    {
        perror(argv[1]);
        return 2;
    }
    write(STDOUT_FILENO, "Number of students ", 20);
    read(STDIN_FILENO,&temp,BUFFER_SIZE);
    int j = atoi(temp);
    while (j != 0)
    {
        i = 0;
        write(STDOUT_FILENO, "Enter the name (limit 512 char end with enter): ", 48);
        while (read(STDIN_FILENO, &chr, 1) && chr != '\n')
        {
            buffer[i++] = chr;
        }
        write(fd1, &buffer, i); // writes name
        i = 0;
        write(STDOUT_FILENO, "Enter the grade value (enter): ", 32);
        write(fd1, " ", 1); // delimeter

    
        while (read(STDIN_FILENO, &chr, 1) && chr != '\n')
        {
            if(chr >= 0 && chr <= 9)
            buffer[i++] = chr;
        }
        write(fd1, &buffer, i); // writes name
        write(fd1, "\n", 1);

        j--;
    }

    close(fd1);
    return 0;
}
