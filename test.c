#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig)
{
    printf("Received signal: %d\n", sig);
}

int main()
{
    signal(SIGUSR1, handle_signal);  // Register SIGUSR1 handler

    printf("Process ID: %d\n", getpid());
    while (1)
        pause();  // Wait for signals

    return 0;
}
