#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	i = 1;
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