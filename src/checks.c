/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:20:58 by jmiguele          #+#    #+#             */
/*   Updated: 2025/11/27 13:10:27 by jmiguele         ###   ########.fr       */
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
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		ft_printf("Error: Command arguments cannot be empty\n");
		exit(1);
	}
	if (argv[1][0] == '\0' || argv[4][0] == '\0')
	{
		ft_printf("Error: file argument cannot be empty\n");
		exit(1);
	}
}
