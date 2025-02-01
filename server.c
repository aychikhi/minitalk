/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:58:42 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/01 13:15:47 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"


void handler_sig(int sig)
{
    if (sig == SIGUSR2)
	    write(1, "1", 1);
    else if (sig == SIGUSR1)
        write(1, "0", 1);
}

int main()
{
    printf("Server PID: %d\n", getpid());
    signal(SIGUSR1, handler_sig);
    signal(SIGUSR2, handler_sig);
    while (1)
    {
        pause();
    }
    return (0);
}
