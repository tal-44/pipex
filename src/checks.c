/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanm <juanm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:20:58 by jmiguele          #+#    #+#             */
/*   Updated: 2025/11/27 16:02:48 by juanm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_files(char *file, int mode)
{
	if (mode == 0)
	{
		if (access(file, F_OK) == -1)
		{
			perror(file);
			return (-1);
		}
		if (access(file, R_OK) == -1)
		{
			perror(file);
			return (-1);
		}
	}
	if (mode == 1)
	{
		if ((access(file, F_OK) != -1) && access(file, W_OK) == -1)
		{
			perror(file);
			return (-1);
		}
	}
	return (0);
}

static int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Error: Invalid number of arguments\n");
		exit(1);
	}
	if (!argv[1] || !argv[2] || !argv[3] || !argv[4])
	{
		ft_printf("Error: One or more arguments are null\n");
		exit(1);
	}
	if (check_spaces(argv[2]) || check_spaces(argv[3]) || argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		ft_printf("Error: Command arguments cannot be empty\n");
		exit(1);
	}
	if (check_spaces(argv[1]) || check_spaces(argv[4]) || argv[1][0] == '\0' || argv[4][0] == '\0')
	{
		ft_printf("Error: file argument cannot be empty\n");
		exit(1);
	}
}
