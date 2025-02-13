/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:25:47 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/13 13:15:30 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	error_mess(int flag)
{
	if (flag == 1)
		ft_putendl_fd("please enter : ./client <server PID> <messsage>", 2);
	else
		ft_putendl_fd("invalid PID", 2);
	exit(1);
}

void	mess_oppo(int sig)
{
	if (sig == SIGUSR1)
		ft_putendl_fd("-> Message was sent successfully ✅", 1);
}

void	send_null(int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		kill(pid, SIGUSR1);
		bit--;
		usleep(500);
	}
}

void	send_mess(char *mess, int pid)
{
	char	c;
	int		bit;
	int		check;

	check = 0;
	while (*mess)
	{
		c = *mess;
		bit = 7;
		while (bit >= 0)
		{
			if (c & (1 << bit))
				check = kill(pid, SIGUSR2);
			else
				check = kill(pid, SIGUSR1);
			if (check == -1)
				error_mess(2);
			bit--;
			usleep(500);
		}
		mess++;
	}
	send_null(pid);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		error_mess(1);
	signal(SIGUSR1, mess_oppo);
	pid = ft_atoi(av[1]);
	if (ft_atoi(av[1]) <= 0)
		error_mess(2);
	send_mess(av[2], pid);
}
