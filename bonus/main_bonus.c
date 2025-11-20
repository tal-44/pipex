/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipex <pipex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by pipex             #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by pipex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		ft_error("Error: Invalid number of arguments\n");
		return (1);
	}
	(void)argv;
	(void)envp;
	return (0);
}
