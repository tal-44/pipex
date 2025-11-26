
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../src/utils/ft_printf/ft_printf.h"

// Utils functions
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
void	free_split(char **split);

// Check functions
void	check_files(char *infile, char *outfile);
void	check_args(int argc, char **argv);

// File operations
int		openOrCreateFile(char *filename, int mode);

// Execute functions
char	*search_in_paths(char **paths, char *cmd);
char	*get_cmd_path(char *cmd, char **envp);
void	execute(char *cmd, char **envp);

// Pipex functions
void	child_processIn(int pipefd[2], char **argv, char **envp);
void	child_processOut(int pipefd[2], char **argv, char **envp);
int		pipex(char **argv, char **envp);

#endif
