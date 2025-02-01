/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:58:42 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/01 12:20:38 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

void handler_sig1(int sig)
{
	printf("0");
}

void handler_sig2(int sig)
{
	printf("1");
}

int main()
{
	struct sigaction sa1, sa2;

    printf("Server PID: %d\n", getpid());
	sa1.sa_handler = handler_sig1;
    sigemptyset(&sa1.sa_mask);
    sa1.sa_flags = 0;
    sa2.sa_handler = handler_sig2;
    sigemptyset(&sa2.sa_mask);
    sa2.sa_flags = 0;
    sigaction(SIGUSR1, &sa1, NULL);
    sigaction(SIGUSR2, &sa2, NULL);
    while (1)
    {
        pause();
    }
    return (0);
}
