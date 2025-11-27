/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:21:04 by jmiguele          #+#    #+#             */
/*   Updated: 2025/11/27 12:39:12 by jmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_or_create_file(char *filename, int mode)
{
	int	fd;

	fd = -2;
	if (mode == 0)
	{
		if (check_files(filename, mode) == 0)
			fd = open(filename, O_RDONLY);
		if (fd == -1)
			perror(filename);
		if (fd < 0)
			return (-1);
	}
	else if (mode == 1)
	{
		if (check_files(filename, mode) == 0)
			fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			perror(filename);
		if (fd < 0)
			return (-1);
	}
	return (fd);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc((len1 + len2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcpy(str + len1, s2, len2 + 1);
	return (str);
}

char	*ft_strdup(const char *src)
{
	size_t			i;
	unsigned char	*dest;

	dest = (unsigned char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ((char *)(dest));
}
