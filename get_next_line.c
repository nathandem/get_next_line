/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:58:04 by nde-maes          #+#    #+#             */
/*   Updated: 2018/12/03 16:15:16 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

/*
** `0` has been added to all memory ranges dynamically allocated for easier
** manipulation (temp_buff, read_buff and *line)
*/

int				ft_nlchr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char			*ft_strnjoin(char *s1, char *read_buff, int len)
{
	char			*ns;

	if (!(ns = ft_strnew(ft_strlen(s1) + len)))
		return (NULL);
	ft_strcpy(ns, s1);
	free(s1);
	ft_strncat(ns, read_buff, len);
	return (ns);
}

char			*ft_strcutstart(char *s, int start)
{
	char			*ns;

	ns = ft_strdup(s + start);
	free(s);
	return (ns);
}

/*
** tmp_buff is first arbitrarily allocated to avoid segfault during first
** access in `ft_nlchr`
** if len(tmp_buff) < BUFF_SIZE && read_flag and no nl in tmp_buff,
** it's the last line and no nl at the end of it!
*/

int				get_next_line(const int fd, char **line)
{
	static char		*tmp_buff;
	char			*read_buff;
	int				read_flag;
	int				nl;
	int				ret;

	if (!tmp_buff && !(tmp_buff = ft_strnew((unsigned int)9)))
		return (-1);
	if (!(read_buff = ft_strnew((unsigned int)(BUFF_SIZE + 1))))
		return (-1);
	read_flag = 0;
	while (1)
	{
		if (((nl = ft_nlchr(tmp_buff)) != -1) ||
			(read_flag && ft_strlen(tmp_buff) < BUFF_SIZE))
		{
			if (nl != -1)
				*line = ft_strsub(tmp_buff, (unsigned int)0, (unsigned int)nl);
			else
				*line = ft_strdup(tmp_buff);
			tmp_buff = ft_strcutstart(tmp_buff, nl + 1);
			free(read_buff);
			return (1);
		}
		ret = read(fd, read_buff, BUFF_SIZE);
		read_flag = 1;
		if (ret == 0)
		{
			free(read_buff);
			if (!(*line = ft_strnew((unsigned int)0)))
				return (-1);
			return (0);
		}
		if (ret == -1)
		{
			free(read_buff);
			return (-1);
		}
		if (!(tmp_buff = ft_strnjoin(tmp_buff, read_buff, ret)))
			return (-1);
	}
}
