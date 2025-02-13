/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:42:14 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/13 11:34:33 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_mess(void)
{
	ft_putendl_fd("invalid arguments", 2);
	exit(1);
}

void	send_mess(char *mess, int pid)
{
	char	c;
	int		bit;
	
	while (*mess)
	{
		c = *mess;
		bit = 7;
		while (bit >= 0)
		{
			if (c & (1 << bit))
				kill(SIGUSR2, pid);
			else
				kill(SIGUSR1, pid);
			bit--;
		}
		mess++;
		usleep(500);
	}
}

int main(int ac, char **av)
{
	int		pid;

	if (ac == 1 || ac != 3)
		error_mess();
	pid = ft_atoi(av[2]);
	if (ft_atoi(av[1]) <= 0)
		return (0);
	send_mess(av[2], pid);
}
