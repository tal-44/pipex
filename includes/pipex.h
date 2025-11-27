/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanm <juanm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:29:39 by jmiguele          #+#    #+#             */
/*   Updated: 2025/11/27 17:04:44 by juanm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../src/utils/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

// Utils functions
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char *s1, char const *set);

// Check functions
void	check_args(int argc, char **argv);

// File operations
int		check_files(char *file, int mode);
int		open_or_create_file(char *filename, int mode);

// Execute functions
void	execute(char *cmd, char **envp);

// Pipex functions
int		pipex(char **argv, char **envp);

#endif
