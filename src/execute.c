#include "pipex.h"

char	*search_in_paths(char **paths, char *cmd)
{
	char	*full_path;
	char	*temp;
	int		j;

	j = 0;
	while (paths[j])
	{
		temp = ft_strjoin(paths[j], "/");
		if (!temp)
			break;
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (!full_path)
			break;
		if (access(full_path, X_OK) == 0)
		{
			free_split(paths);
			return (full_path);
		}
		free(full_path);
		j++;
	}
	free_split(paths);
	return (NULL);
}

char *get_cmd_path(char *cmd, char **envp)
{
	char	*path;
	char	**paths;
	int		i;

	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			paths = ft_split(path, ':');
			if (!paths)
				return (NULL);
			return (search_in_paths(paths, cmd));
		}
		i++;
	}
	return (NULL);
}

// 127 stands for "command not found" error code
void	execute(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
	{
		ft_printf("Error: Memory allocation failed\n");
		exit(1);
	}
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		write(2, "bash: ", 6);
		write(2, cmd_args[0], ft_strlen(cmd_args[0]));
		write(2, ": command not found\n", 20);
		free_split(cmd_args);
		exit(127);
	}

	execve(cmd_path, cmd_args, envp);
	perror("execve");
	free_split(cmd_args);
	free(cmd_path);
	exit(127);
}
