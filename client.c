/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:46:11 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/01 13:14:09 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send_signal(const char *str, int pid)
{
	char	c;
	int		i;

	while (*str)
	{
		c = *str;
		i = 128;
		while (i > 0)
		{
			if (c < i)
			{
				kill(pid, SIGUSR1);
				printf("0");
			}
			else
			{
				kill(pid, SIGUSR2);
				c -= i;
				printf("1");
			}
			i /= 2;
			usleep(50);
		}
		printf("	");
		usleep(200);
		str++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac != 3)
	{
		printf("please enter : %s <server PID> <messsage>", av[0]);
		return (1);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	send_signal(str, pid);
}
