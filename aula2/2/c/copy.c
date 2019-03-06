#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <sys/times.h>
#define BUF_LENGTH 256

int main(int argc, char **argv)
{
    FILE *src, *dst;
    if (argc == 3)
    {
        char *file1 = argv[1];
        char *file2 = argv[2];

        char buf[BUF_LENGTH];

        clock_t start, end;
        double cpu_time_used;
        struct tms t;
        long ticks;
        start = times(&t);
        ticks = sysconf(_SC_CLK_TCK);

        if ((src = fopen(file1, "r")) == NULL)
        {
            printf("Couldn't open file: Error number %i\n", errno);
            exit(1);
        }
        if ((dst = fopen(file2, "w")) == NULL)
        {
            printf("Couldn't create file: Error number %i\n", errno);
            exit(2);
        }
        while ((fgets(buf, BUF_LENGTH, src)) != NULL)
        {
            fputs(buf, dst);
        }
        printf("\nClock ticks per second: %ld\n", ticks);

        end = times(&t);

        printf("Clock:                %4.2f s\n", (double)(end - start) / ticks);
        printf("User time:            %4.2f s\n", (double)t.tms_utime / ticks);
        printf("System time:          %4.2f s\n", (double)t.tms_stime / ticks);
        fclose(src);
        fclose(dst);
    }

    exit(0); // zero é geralmente indicativo de "sucesso"
}