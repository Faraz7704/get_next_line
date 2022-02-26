/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:41:22 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/26 23:00:34 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str, char sep)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && c != str[i])
		i++;
	if (c == str[i])
		return ((char *)(str + i));
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n, char sep)
{
	size_t	i;
	size_t	srcsize;

	if (!src)
		return (0);
	i = 0;
	srcsize = ft_strlen(src, sep);
	if (n > 0)
	{
		while (src[i] != sep && i < n - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = src[i];
	}
	return (srcsize);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n, char sep)
{
	size_t	i;
	size_t	j;

	if (!src)
		return (0);
	j = ft_strlen(dest, sep);
	if (n <= j)
		return (n + ft_strlen(src, sep));
	i = 0;
	while (src[i] != sep && j < n - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (ft_strlen(dest, sep) + ft_strlen(&src[i], sep));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		s1_size;
	int		total_size;

	s1_size = ft_strlen(s1, '\0');
	total_size = s1_size + ft_strlen(s2, '\0') + 1;
	if (total_size == 1)
		return (0);
	result = (char *)malloc(sizeof(char) * total_size);
	if (result)
	{
		ft_strlcpy(result, s1, s1_size + 1, '\0');
		ft_strlcat(result, s2, total_size, '\0');
	}
	return (result);
}
