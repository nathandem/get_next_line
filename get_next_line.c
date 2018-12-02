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

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

// to be removed when function is ready (with printf)
#include <stdio.h>

/*
** To make things simpler add a `0` to all memory ranges I allocate for easier
** manipulation (temp_buff, read_buff and *line)
*/

unsigned int	ft_nlchr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
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

char			*ft_strnjoin(char *s1, char *read_buff, int len)
{
	char			*ns;

	// if compiler super rigorous, s1 unsigned and len signed
	if (!(ns = ft_strnew(ft_strlen(s1) + len)))
		return (NULL);
	ft_strcpy(ns, s1);
	free(s1);
	ft_strncat(ns, read_buff, len);
	return (ns);
}

/*
** `nl` = index of `\n` in `tmp_buff`
*/

int				get_next_line(const int fd, char **line)
{
	static char		*tmp_buff;
	char			*read_buff;
	unsigned int	nl;
	int				ret;

	printf("tmp_buff: %s (value should change the other times)\n", tmp_buff);
	if (!tmp_buff)
		tmp_buff = ft_strnew((unsigned int)9); // arbitrary assignation to avoid segfault during first access in `ft_nlchr`
	read_buff = ft_strnew((unsigned int)(BUFF_SIZE + 1)); // to be freed
	while (1)
	{
		if ((nl = ft_nlchr(tmp_buff)))
		{
			printf("next nl at: %d\n", (int)nl);
			// nl is excluded from the new string
			*line = ft_strsub(tmp_buff, (unsigned int)0, nl);
			tmp_buff = tmp_buff + nl + 1; // NOT CLEAN
			free(read_buff);
			return (1);
		}
		ret = read(fd, read_buff, BUFF_SIZE);
		printf("ret: %d\n", ret);
		if (ret == 0)
		{
			free(tmp_buff);
			free(read_buff);
			return (0);
		}
		if (ret == -1)
			return (-1);
		if (!(tmp_buff = ft_strnjoin(tmp_buff, read_buff, ret)))
		return (-1);
		printf("new tmp_buff after joining read_buff: %s\n", tmp_buff);
	}
}
