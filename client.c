#include "mini_talk.h"


void send_text(int pid, char *str)
{
    int i;
    int bit;

    i = 0;
    while(str[i])
    {
        bit = 7;
        while (bit >= 0)
        {
            if ((str[i] >> bit & 1) == 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            bit--;
            usleep(800);
        }
        i++;
    }
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
    if (str[i] == '0')
    {
        return -1;
    }
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
    if (str[i] != '\0' || result <= 0)
       { return -1;}
	return (result);
}

int main(int ac, char *av[])
{
    int pid;

    if (ac == 3)
    {
        pid = ft_atoi(av[1]);
        if (pid <= 0)
        {
            ft_printf("error, invalid PID\n");
            exit(1);
        }
        send_text(pid, av[2]);
    }
    return (0);
}