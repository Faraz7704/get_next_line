/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:07:34 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/25 16:13:36 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> 
//ADDED FOR TESTING ONLY
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str, char sep);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t n, char sep);
size_t	ft_strlcat(char *dest, const char *src, size_t n, char sep);
char	*ft_strjoin(char *s1, char *s2);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 0
#endif

#endif