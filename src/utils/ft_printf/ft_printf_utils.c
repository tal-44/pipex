/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanm <juanm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 10:39:33 by jmiguele          #+#    #+#             */
/*   Updated: 2025/11/25 18:47:32 by juanm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// 0 for lowercase, 1 for uppercase
void	puthex_fd(unsigned long num, const char format, int *printed_chars)
{
	char	*cadena_hex;

	cadena_hex = "0123456789abcdef";
	if (num >= 16)
		puthex_fd(num / 16, format, printed_chars);
	if (format == 0)
		ft_putchar_fd(cadena_hex[num % 16], 1);
	else
		ft_putchar_fd(ft_toupper(cadena_hex[num % 16]), 1);
	(*printed_chars)++;
}

void	putstr_fd(char *s, int fd, int *printed_chars)
{
	int	i;

	i = 0;
	if (!s)
	{
		putstr_fd("(null)", fd, printed_chars);
		return ;
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		(*printed_chars)++;
		i++;
	}
}

void	putnbr_fd(int n, int fd, int *printed_chars)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		(*printed_chars)++;
		num = -num;
	}
	if (num >= 10)
		putnbr_fd((int)(num / 10), fd, printed_chars);
	ft_putchar_fd(('0' + (num % 10)), fd);
	(*printed_chars)++;
}

void	putunsnbr_fd(unsigned int num, int fd, int *printed_chars)
{
	if (num >= 10)
		putunsnbr_fd(num / 10, fd, printed_chars);
	ft_putchar_fd('0' + (num % 10), fd);
	(*printed_chars)++;
}
