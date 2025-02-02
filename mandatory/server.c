/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:58:42 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/02 12:35:01 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	holder;
	static int	bits;
	static int	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		bits = 0;
		holder = 0;
	}
	pid = info->si_pid;
	if (sig == SIGUSR2)
		holder |= (1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		write(1, &holder, 1);
		bits = 0;
		holder = 0;
	}
}

int	main(void)
{
	struct sigaction	sig1;

	ft_putstr_fd("sever PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sig1.sa_flags = SA_SIGINFO;
	sig1.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sig1, NULL);
	sigaction(SIGUSR2, &sig1, NULL);
	while (1)
		pause();
}
