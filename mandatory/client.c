/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:42:14 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/13 13:04:45 by aychikhi         ###   ########.fr       */
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
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		error_mess(1);
	pid = ft_atoi(av[1]);
	if (ft_atoi(av[1]) <= 0)
		error_mess(2);
	send_mess(av[2], pid);
}
