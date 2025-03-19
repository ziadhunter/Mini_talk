#include "mini_talk.h"

int main()
{
    pid_t pid;

    struct sigaction sa;


    pid = getpid();
    printf("My PID: %d\n", pid);
}