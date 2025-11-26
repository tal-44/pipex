
#include "pipex.h"

int openOrCreateFile(char *filename, int mode)
{
    int fd;

    if (mode == 0)
    {
		fd = open(filename, O_RDONLY);
		if (fd < 0)
		{
			perror(filename);
			return (-1);
		}
    }
    else if (mode == 1)
    {
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
		{
			perror(filename);
			return (-1);
		}
    }
    return (fd);
}
