/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipex <pipex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by pipex             #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by pipex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char	*find_path(char *cmd, char **envp)
{
	(void)cmd;
	(void)envp;
	return (NULL);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	*path;
	char	*args[3];

	path = find_path(cmd, envp);
	args[0] = cmd;
	args[1] = NULL;
	args[2] = NULL;
	if (execve(path, args, envp) == -1)
		ft_error("Error: Command execution failed\n");
}
