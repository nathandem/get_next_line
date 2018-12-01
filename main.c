#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

/*
** `print_buff` could print:
** 1) a length of BUFF_SIZE but *line could have a buf bigger than
** BUFF_SIZE (the opposite doesn't make sense). Also, at the end of
** the file, we could read less than BUFF_SIZE than hit end of file.
** 2) what's in `*line` until reaching a terminating 0
** => it depends what we return in *line
*/

void		print_buff(char **line)
{
	write(1, *line, BUFF_SIZE);
	write(1, "\n", 1);
}

int			main(void)
{
	int			fd;
	int			ret;
	int			call_counter;
	char		**line = NULL;

	if ((fd = open("test.txt", O_RDONLY)) == -1)
	{
		dprintf(2, "Error opening the file\n");
		return (1);
	}
	printf("fd: %d\n", fd);
	ret = 1;
	call_counter = 0;
	while (ret)
	{
		if ((ret = get_next_line(fd, line)) == -1)
			return (1);
		call_counter++;
		printf("*line: %s (on call nb: %d)\n", *line, call_counter);
	}
	if (close(fd) == -1)
	{
		dprintf(2, "Error closing the file\n");
		return (1);
	}
	return (0);
}
