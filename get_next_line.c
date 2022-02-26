/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:06:22 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/26 23:16:40 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_savebuff(char *buffer)
{
	int		len;
	int		linelen;
	char	*newbuff;

	linelen = ft_strlen(buffer, '\n');
	len = ft_strlen(buffer, '\0') - linelen;
	if (len <= 0 || !buffer[0])
	{
		free(buffer);
		return (0);
	}
	newbuff = malloc(sizeof(char) * (len + 1));
	if (!newbuff)
		return (0);
	ft_strlcpy(newbuff, &buffer[linelen + 1], len, '\0');
	if (!newbuff[0])
	{
		free(newbuff);
		newbuff = NULL;
	}
	free(buffer);
	return (newbuff);
}

char	*ft_readline(int fd, char *buffer)
{
	char	*localbuff;
	char	*newbuff;
	int		result;

	localbuff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!localbuff)
		return (0);
	localbuff[0] = '\0';
	result = 1;
	while (result != 0 && !ft_strchr(localbuff, '\n'))
	{
		result = read(fd, localbuff, BUFFER_SIZE);
		if (result < 0)
			break ;
		localbuff[result] = '\0';
		newbuff = ft_strjoin(buffer, localbuff);
		free(buffer);
		buffer = newbuff;
	}
	free(localbuff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_readline(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_strdup(buffer, '\n');
	buffer = ft_savebuff(buffer);
	return (line);
}
