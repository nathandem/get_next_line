/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:54:17 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 10:33:50 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

/*
** This function could have relied more on libft, to allocate the string memory
** and set its terminating 0 (`ft_strnew`). Then `ft_strncat` could have helped
** for the copy of the good part of `s` into `ns`.
**
** `ft_strtrim` is typically a function to test during dev to make sure we
** don't incude mistakes, cause it's easy to make some.
*/

char		*ft_strtrim(char const *s)
{
	int				i;
	int				s_start;
	int				s_end;
	char			*ns;

	if (!s)
		return (NULL);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	s_start = i;
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > s_start)
		i--;
	s_end = i;
	if ((ns = ft_strnew(s_end - s_start + 1)) == NULL)
		return (NULL);
	i = -1;
	while (++i + s_start <= s_end)
		ns[i] = s[s_start + i];
	ns[i] = 0;
	return (ns);
}
