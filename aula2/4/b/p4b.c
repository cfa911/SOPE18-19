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

#define BUFFER_SIZE 50

struct student
{
    char name[BUFFER_SIZE];
    int grade;
};

int main(int argc, char **argv)
{

    FILE *fd1;
    int i = 0,value;
    char chr, temp[BUFFER_SIZE];
    unsigned char buffer[BUFFER_SIZE];

    if (argc != 2)
    {
        printf("Usage: %s <source> \n", argv[0]);
        return 1;
    }
    fd1 = fopen(argv[1], "a+");
    if (fd1 == NULL)
    {
        perror(argv[1]);
        return 2;
    }
    write(STDOUT_FILENO, "Number of students ", 20);
    read(STDIN_FILENO, &temp, BUFFER_SIZE);
    int j = atoi(temp);
    while (j != 0)
    {
        struct student *object = malloc(sizeof(struct student));
        i = 0;
        write(STDOUT_FILENO, "Enter the name (limit 512 char end with enter): ", 48);
        while (read(STDIN_FILENO, &chr, 1) && chr != '\n')
        {
            buffer[i++] = chr;
        }
        strcpy(object->name, buffer);
        
        
        write(STDOUT_FILENO, "Enter the grade value (enter): ", 32);
        read(STDIN_FILENO, &temp, BUFFER_SIZE);
        value = atoi(temp);
        object->grade = value;
        fwrite(object, sizeof(struct student), 1, fd1);
	memset(buffer,0,i);
        j--;
    }
    fclose(fd1);
    return 0;
}
