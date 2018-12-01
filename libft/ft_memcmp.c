/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:10:57 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 08:51:10 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** As opposed to strcmp which look at all but stops at `0` bytes,
** memcmp introspects all bytes (including the `0` byte)
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = -1;
	while (++i < n)
		if (((unsigned char*)s1)[i] != ((unsigned char*)s2)[i])
			return (int)(((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	return (0);
}
