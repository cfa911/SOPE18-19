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
    struct student *object2 = malloc(sizeof(struct student));
    FILE *file = fopen(argv[1], "rb");
    
    if (file != NULL)
    {
        fread(object2, sizeof(struct student), 1, file);
        printf("Student:%s Grade:%i\n", object2->name, object2->grade);
        
    }
   fclose(file);
}