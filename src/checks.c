
#include "pipex.h"

void check_files(char *infile, char *outfile)
{
	if (access(infile, F_OK) == -1)
	{
		perror(infile);
		exit(1);
	}
	if (access(infile, R_OK) == -1)
	{
		perror(infile);
		exit(1);
	}
	if ((access(outfile, F_OK) != -1) && access(outfile, W_OK) == -1)
	{
		perror(outfile);
		exit(1);
	}
}

void check_args(int argc, char **argv)
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
    check_files(argv[1], argv[4]);
}
