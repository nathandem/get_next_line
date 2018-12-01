/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:58:04 by nde-maes          #+#    #+#             */
/*   Updated: 2018/12/01 20:45:56 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

/*
** To make things simpler add a `0` to all memory ranges I allocate for easier
** manipulation (temp_buff, read_buff and *line)
*/

int			ft_nlchr(char *str)
{
	int				i;

	i = 0;
	while (i < len && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

/*
** ft_strnjoin is not protected on purpose to avoid returning NULL at the 1st
** call of the function when tmp_buff points to NULL
*/

char		*ft_strnjoin(char *s1, char *s2, unsigned int len)
{
	char			*nstr;

	if (!(nstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(ns, s1);
	free(s1);
	ft_strncat(ns, s2, len);
	return (ns);
}

/*
** `nl` = index of `\n` in `tmp_buff`
*/

int			get_next_line(const int fd, char **line)
{
	static char		*tmp_buff;
	char			*read_buff;
	unsigned int	nl;
	unsigned int	ret;

	read_buff = ft_strnew((unsigned int)(BUFF_SIZE + 1)); // to be freed
	while (1)
	{
		if (nl = ft_nlchr(tmp_buff))
		{
			/* line: section of tmp_buff starting at 0 and ending on char before nl */
			*line = ft_strsub(tmp_buff, (unsigned int)0, nl - 1);
			/* new tmp_buff points to char after nl on old tmp_buff */
			tmp_buff = tmp_buff + nl + 1; // attention: ne pas oublier de free
			free(read_buff);
			return ;
		}
		ret = read(fd, read_buff, BUFF_SIZE);
		if (ret == 0 || ret == -1)
			!ret ? return (0) : return (-1);
		tmp_buff = ft_strnjoin(tmp_buff, read_buff, ret);
	}
}
