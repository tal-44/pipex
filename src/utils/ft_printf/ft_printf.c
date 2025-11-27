/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:29:18 by jmiguele          #+#    #+#             */
/*   Updated: 2025/11/27 10:24:01 by jmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(const char type, va_list args, int *printed_chars)
{
	unsigned long	ptr_value;

	if (type == 'p')
	{
		ptr_value = va_arg(args, unsigned long);
		if (!ptr_value)
			putstr_fd("(nil)", 1, printed_chars);
		else
		{
			putstr_fd("0x", 1, printed_chars);
			puthex_fd(ptr_value, 0, printed_chars);
		}
	}
	else if (type == 'x')
		puthex_fd(va_arg(args, unsigned int), 0, printed_chars);
	else if (type == 'X')
		puthex_fd(va_arg(args, unsigned int), 1, printed_chars);
	else if (type == '%')
	{
		ft_putchar_fd('%', 1);
		(*printed_chars)++;
	}
}

static void	print(const char type, va_list args, int *printed_chars)
{
	if (type == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*printed_chars)++;
	}
	else if (type == 's')
		putstr_fd(va_arg(args, char *), 1, printed_chars);
	else if (type == 'd' || type == 'i')
		putnbr_fd(va_arg(args, int), 1, printed_chars);
	else if (type == 'u')
		putunsnbr_fd(va_arg(args, unsigned int), 1, printed_chars);
	else
		print_hex(type, args, printed_chars);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		printed_chars;

	va_start(args, input);
	printed_chars = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] != '%')
		{
			ft_putchar_fd(input[i], 1);
			i++;
			printed_chars++;
			continue ;
		}
		if (input[++i])
		{
			print(input[i], args, &printed_chars);
			i++;
		}
	}
	va_end(args);
	return (printed_chars);
}
