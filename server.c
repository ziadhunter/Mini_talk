#include "mini_talk.h"

void handler_input(int sig)
{
    static int i;
    static char one_character;

    if (sig == SIGUSR2)
        one_character |= (1 << (7 - i));
    i++;
    if (i == 8)
    {
        write(1, &one_character, 1);
        i = 0;
        one_character = 0;
    }
}

int main()
{
    pid_t pid;
    struct sigaction sig_conf;
    sig_conf.sa_handler = handler_input;
    sig_conf.sa_flags = 0;
    sigemptyset(&sig_conf.sa_mask);
    sigaction(SIGUSR1, &sig_conf, NULL);
    sigaction(SIGUSR2, &sig_conf, NULL);
    pid = getpid();
    printf("My PID: %d\n", pid);
    while (1)
    {
        pause();
    }
}

























