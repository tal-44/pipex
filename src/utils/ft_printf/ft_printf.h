/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:39:30 by jmiguele          #+#    #+#             */
/*   Updated: 2025/11/27 11:28:53 by jmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);

char	ft_toupper(char c);
void	ft_putchar_fd(char c, int fd);
void	puthex_fd(unsigned long num, const char format, int *printed_chars);
void	putstr_fd(char *s, int fd, int *printed_chars);
void	putnbr_fd(int n, int fd, int *printed_chars);
void	putunsnbr_fd(unsigned int num, int fd, int *printed_chars);

#endif
