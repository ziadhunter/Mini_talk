/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:24:44 by zfarouk           #+#    #+#             */
/*   Updated: 2025/03/20 21:42:34 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	handle_input(int sig, siginfo_t *info, void *context)
{
	static int		i;
	static char		one_character;
	static pid_t	old_process;

	(void)context;
	if (old_process != info->si_pid)
	{
		old_process = info->si_pid;
		i = 0;
		one_character = '\0';
	}
	if (sig == SIGUSR2)
		one_character |= (1 << (7 - i));
	i++;
	if (one_character == '\0' && i == 8)
		kill(info->si_pid, SIGUSR1);
	if (i == 8)
	{
		write(1, &one_character, 1);
		i = 0;
		one_character = 0;
	}
}

int	main(int ac, char *av[])
{
	pid_t			pid;
	struct sigaction	sig_conf;

	(void)av;
	if (ac == 1)
	{
		sig_conf.sa_sigaction = handle_input;
		sig_conf.sa_flags = SA_SIGINFO;
		sigemptyset(&sig_conf.sa_mask);
		sigaction(SIGUSR1, &sig_conf, NULL);
		sigaction(SIGUSR2, &sig_conf, NULL);
		pid = getpid();
		ft_printf("My PID: %d\n", pid);
		while (1)
		{
			pause();
		}
	}
	return (0);
}

