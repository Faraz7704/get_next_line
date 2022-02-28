/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:41:22 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/28 15:20:51 by fkhan            ###   ########.fr       */
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

char	*ft_strdup(const char *str, char sep)
{
	int		len;
	char	*result;

	len = ft_strlen(str, sep) + 1;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, str, len, sep);
	result[len] = '\0';
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		total_size;
	char	*result;

	i = 0;
	j = 0;
	total_size = ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1;
	if (total_size == 1)
		return (0);
	result = (char *)malloc(total_size);
	if (!result)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
