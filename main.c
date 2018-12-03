#include <stdio.h>
#include "get_next_line.h"

int			main(void)
{
	char		*line = NULL;
	int			ret;

	ret = get_next_line(0, &line);

	printf("res: %d, *line: %s\n", ret, line);

	return (0);
}
