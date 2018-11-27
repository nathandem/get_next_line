#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

void		print_buff(char **line)
{
	write(1, *line, BUFF_SIZE);
	write(1, "\n", 1);
}

int			main(void)
{
	int			fd;
	int			ret;

	if ((fd = open("test.txt", O_RDONLY)) == -1)
	{
		printf("Error opening the file\n");
		return (1);
	}
	ret = 1;
	while (ret)
	{
		if ((ret = get_next_line(fd, line)) == -1)
			return (1);
		print_buff(line);
	}
	if (close(fd) == -1)
	{
		printf("Error closing the file\n");
		return (1);
	}
	return (0);
}
