
#include "pipex.h"

static int	handle_error(char *error_msg, int pipefd[2])
{
	if (pipefd)
	{
		close(pipefd[0]);
		close(pipefd[1]);
	}
	perror(error_msg);
	return (1);
}

void	child_processIn(int pipefd[2], char **argv, char **envp)
{
	int	infd;
	int	err;

	err = 0;
	infd = openOrCreateFile(argv[1], 0);
	if (infd < 0)
		err = -1;
	if (err == 0 && dup2(infd, 0) < 0)
	{
		perror("dup2");
		err = -1;
	}
	if (err == 0 && dup2(pipefd[1], 1) < 0)
	{
		perror("dup2");
		err = -1;
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(infd);
	if (err < 0)
		exit(1);
	execute(argv[2], envp);
	exit(0);
}

void	child_processOut(int pipefd[2], char **argv, char **envp)
{
	int	outfd;
	int	err;

	err = 0;
	outfd = openOrCreateFile(argv[4], 1);
	if (outfd < 0)
		err = -1;
	if (err == 0 && dup2(pipefd[0], 0) < 0)
	{
		perror("dup2");
		err = -1;
	}
	if (err == 0 && dup2(outfd, 1) < 0)
	{
		perror("dup2");
		err = -1;
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(outfd);
	if (err < 0)
		exit(1);
	execute(argv[3], envp);
	exit(0);
}

int pipex(char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(pipefd) == -1)
		return (handle_error("Error: pipe failed", NULL));
	pid1 = fork();
	if (pid1 == -1)
		return (handle_error("Error: fork failed", pipefd));
	if (pid1 == 0)
		child_processIn(pipefd, argv, envp);
	close(pipefd[1]);
	pid2 = fork();
	if (pid2 == -1)
		return (handle_error("Error: fork failed", pipefd));
	if (pid2 == 0)
		child_processOut(pipefd, argv, envp);
	close(pipefd[0]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (1);
}
