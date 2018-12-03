#include "get_next_line.h"

char		*strnewfromfree(char *s, int start)
{
	char			*ns;

	if (!s || (!(ns = ft_strnew(ft_strlen(s) - start))))
		return (NULL);
	ft_strcpy(ns, (s + start));
	free(s);
	return (ns);
}

char		*strjoinfree(char *s1, char *s2)
{
	char			*ns;

	if (!s1 || !s2)
		return (NULL);
	if (!(ns = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(ns, s1);
	ft_strcpy(ns + ft_strlen(ns), s2);
	free(s1);
	return (ns);
}

int			get_next_line(const int fd, char **line)
{
	static char		*tmp_buff;
	char			*read_buff;
	char			*nl;
	int				ret;

	if (fd < 3 || !line || BUFF_SIZE < 0)
		return (-1);
	if (!tmp_buff && (!(tmp_buff = ft_strnew(0)))) // needed?
		return (-1);
	if (!(read_buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	
	ret = 1;
	while (!(nl = ft_strchr(tmp_buff, '\n')) || ret)
	{
		if ((ret = read(fd, read_buff, BUFF_SIZE)) == -1)
		{
			free(read_buff);
			return (-1);
		}
		read_buff[ret] = 0;
		if (!ret && !(tmp_buff = strjoinfree(tmp_buff, read_buff)))
		{
			free(read_buff);
			return (-1);
		}
	}

	if (nl)
	{
		if (!(*line = ft_strsub(tmp_buff, (size_t)0, (size_t)(nl - tmp_buff))))
		{
			free(read_buff);
			return (-1);
		}
		if (!(tmp_buff = strnewfromfree(tmp_buff, (int)(nl - tmp_buff))))
		{
			free(read_buff);
			return (-1);
		}
		free(read_buff);
		return (1);
	}

	if (ret)
	{
		*line = tmp_buff;
		free(read_buff);
		return (1);
	}
	else
		return (0);
}
