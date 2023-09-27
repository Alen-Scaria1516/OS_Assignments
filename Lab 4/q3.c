#include <stdio.h>
#include <unistd.h>

int main()
{
    execl("bin/ls","ls","-l","-a",NULL);
    printf("EXEC failed\n");
    return 0;
}