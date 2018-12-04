/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:32:24 by nde-maes          #+#    #+#             */
/*   Updated: 2018/12/04 17:33:49 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char		*strnewfromfree(char *s, int start)
{
	char			*ns;

	if (!s || (!(ns = ft_strnew(ft_strlen(s) - start))))
		return (NULL);
	ft_strcpy(ns, (s + start + 1));
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

int			handle_output(char *nl, char **tmp_buff, char **line)
{
	if (nl)
	{
		if (!(*line = ft_strsub(*tmp_buff,
			(size_t)0, (size_t)(nl - *tmp_buff))))
			return (-1);
		if (!(*tmp_buff = strnewfromfree(*tmp_buff, (int)(nl - *tmp_buff))))
			return (-1);
		return (1);
	}
	if (*tmp_buff[0] != 0)
	{
		if (!(*line = ft_strdup(*tmp_buff)))
			return (-1);
		ft_bzero(*tmp_buff, ft_strlen(*tmp_buff));
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		*tmp_buff;
	char			read_buff[BUFF_SIZE + 1];
	char			*nl;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!tmp_buff && (!(tmp_buff = ft_strnew(0))))
		return (-1);
	ret = 1;
	while (!(nl = ft_strchr(tmp_buff, '\n')) && ret)
	{
		if ((ret = read(fd, read_buff, BUFF_SIZE)) == -1)
			return (-1);
		read_buff[ret] = 0;
		if (!(tmp_buff = strjoinfree(tmp_buff, read_buff)))
			return (-1);
	}
	return (handle_output(nl, &tmp_buff, line));
}
