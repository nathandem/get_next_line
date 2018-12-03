#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int			fd;
	int			ret;
	int			call_counter;
	char		**line;

	if (argc != 2)
		return (1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		dprintf(2, "Error opening the file\n");
		return (1);
	}
	ret = 1;
	/* Initialize *line to a dummy value */
	line = (char**)malloc(10 * sizeof(char*));
	line[0] = ft_strnew(10);
	call_counter = 0;
	while (ret)
	{
		if ((ret = get_next_line(fd, line)) == -1)
			return (1);
		call_counter++;
	}
	if (close(fd) == -1)
	{
		dprintf(2, "Error closing the file\n");
		return (1);
	}
	return (0);
}
