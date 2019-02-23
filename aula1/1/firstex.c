#include <stdio.h>

int main(void)
{
    /*int argc, char *argv[],char *env */
    char str1[30];
    int str2;
    printf("Enter your name: ");
    fgets(str1, 30, stdin);
    printf("Enter the number of times: ");
    scanf("%d", &str2);
    for (int i = 0; i < str2; i++)
    {
        printf("Hello ");
        puts(str1);

    }

    return 0;
}