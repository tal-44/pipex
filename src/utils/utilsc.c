/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguele <jmiguele@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:39:16 by jmiguele          #+#    #+#             */
/*   Updated: 2025/11/27 12:40:42 by jmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*c;
	size_t			i;

	c = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		*c = (unsigned char)value;
		c++;
		i++;
	}
	return (ptr);
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	bytes;
	size_t	max_value;

	if (count == 0 || size == 0)
	{
		return ((void *)malloc(0));
	}
	max_value = (size_t)-1;
	if (count != 0 && size > max_value / count)
		return (NULL);
	bytes = count * size;
	str = (void *)malloc(bytes);
	if (!str)
		return (NULL);
	ft_memset(str, 0, bytes);
	return (str);
}

char	*ft_strtrim(char *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len_total;
	size_t	sublen;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len_total = ft_strlen(s1);
	if (start == len_total)
		return (ft_calloc(1, sizeof(char)));
	end = len_total - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	sublen = end - start + 1;
	str = malloc(sublen + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, sublen + 1);
	return (str);
}
