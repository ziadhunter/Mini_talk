/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:48:44 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/20 21:41:24 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	send_text(int pid, char *str)
{
	int	i;
	int	bit;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((str[i] >> bit & 1) == 0)
				check = kill(pid, SIGUSR1);
			else
				check = kill(pid, SIGUSR2);
			if (check == -1)
				exit(1);
			bit--;
			usleep(900);
		}
		i++;
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

int	main(int ac, char *av[])
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
		{
			ft_printf("error, invalid PID\n");
			exit(1);
		}
		send_text(pid, av[2]);
	}
	return (0);
}

