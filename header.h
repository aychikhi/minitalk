/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:58:49 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/02 13:38:06 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void	mess(int sig);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	send_bits(int pid, char bit);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	send_signal(const char *str, int pid);
void	handler(int sig, siginfo_t *info, void *context);

#endif