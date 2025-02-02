/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:57:51 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/02 12:56:42 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	mess(int sig)
{
	if (sig == SIGUSR2)
		ft_putendl_fd("Message was sent successfully", 1);
}

void	send_signal(const char *str, int pid)
{
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if (*str & (1 << i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			i--;
		}
		usleep(500);
		str++;
	}
	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac != 3)
	{
		ft_putendl_fd("please enter : ./client <server PID> <messsage>", 1);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR2, mess);
	pid = ft_atoi(av[1]);
	str = av[2];
	send_signal(str, pid);
}
