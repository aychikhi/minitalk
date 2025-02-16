/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:42:43 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/15 16:52:02 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_isspace(int c);
int		ft_isdigit(int c);
void	send_null(int pid);
void	mess_oppo(int sig);
int		ft_atoi(char *str);
void	error_mess(int flag);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	send_mess(char *mess, int pid);
void	handler(int sig, siginfo_t *info, void *context);

#endif