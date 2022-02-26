/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:17:54 by fkhan             #+#    #+#             */
/*   Updated: 2022/02/26 23:18:00 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	fd = open("test.txt", O_RDWR);
	i = 1;
	str = get_next_line(fd);
	while (str)
	{
		printf("-------- line %d --------\n", i++);
		printf("%s\n", str);
		printf("-------------------------\n\n");
		str = get_next_line(fd);
	}
	printf("end of line = %d\n", str == NULL);
	close(fd);
	return (0);
}
