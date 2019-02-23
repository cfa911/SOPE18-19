#include <stdio.h>
#include <string.h>
int main(int argc, char **argv, char **env)
{

    for (int i = 0; env[i] != NULL; i++)
    {
        if (!strncmp(env[i], "USER=", 5))
        {
            char *token = strtok(env[i], "=");
            token = strtok(NULL, "=");
            printf("Hello %s\n", token);
        }
    }

    return 0;
}
