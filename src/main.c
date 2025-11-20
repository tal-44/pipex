/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
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
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_error("Error: Invalid number of arguments\n");
		return (1);
	}
	if (pipe(pipefd) == -1)
		ft_error("Error: Pipe failed\n");
	pid = fork();
	if (pid == -1)
		ft_error("Error: Fork failed\n");
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		execute_cmd(argv[2], envp);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	waitpid(pid, NULL, 0);
	execute_cmd(argv[3], envp);
	return (0);
}
