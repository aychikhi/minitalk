/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:26:16 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/13 12:49:45 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	holder;
	static int	bit;
	static int	pid;

	(void)context;
	if (pid != info->si_pid)
	{
		bit = 0;
		holder = 0;
	}
	pid = info->si_pid;
	if (sig == SIGUSR1)
		holder = holder << 1 | 0;
	else if (sig == SIGUSR2)
		holder = holder << 1 | 1;
	bit++;
	if (bit == 8)
	{
		if (holder == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &holder, 1);
		holder = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
