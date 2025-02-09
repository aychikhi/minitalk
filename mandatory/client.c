/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:46:11 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/09 10:26:23 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	send_bits(int pid, char bit)
{
	if (bit == '0')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
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
				send_bits(pid, '1');
			else
				send_bits(pid, '0');
			usleep(500);
			i--;
		}
		str++;
	}
	i = 7;
	while (i >= 0)
	{
		send_bits(pid, '0');
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
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (0);
	str = av[2];
	send_signal(str, pid);
}
