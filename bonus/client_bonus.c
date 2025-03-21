/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:24:33 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/21 00:40:18 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	send_bit(char c, int bit, int pid)
{
    int	check;

    if ((c >> bit & 1) == 0)
        check = kill(pid, SIGUSR1);
    else
        check = kill(pid, SIGUSR2);
    if (check == -1)
        exit(1);
    bit--;
    usleep(900);
}

void	send_text(int pid, char *str)
{
	int	i;
	int	bit;
	i = 0;
	while (str[i])
	{
		bit = 7;
		while (bit >= 0)
        {
            send_bit(str[i], bit, pid);
            bit--;
        }
		i++;
	}
	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(900);
		i--;
	}
}

int	ft_atoi(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (str[i] == '0')
	{
		return (-1);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		if (result > (long)INT_MAX)
			return (-1);
		i++;
	}
	if (str[i] != '\0')
	{
		return (-1);
	}
	return (result);
}

void	received(int sig)
{
	(void)sig;
	ft_printf("The text has been received!\n");
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		signal(SIGUSR1, received);
		if (pid < 0)
		{
			ft_printf("error, invalid PID\n");
			exit(1);
		}
		send_text(pid, av[2]);
	}
	return (0);
}
