
#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	check_args(argc, argv);
	return (pipex(argv, envp));
}
