/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:20:26 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/19 14:27:23 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
** A valid `little` instance in `big` must not exceed a length of `len`
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			llen;
	unsigned int	i;

	if (!*little)
		return ((char*)big);
	llen = ft_strlen(little);
	i = 0;
	while (big[i])
	{
		if (ft_memcmp((const void*)(big + i), (const void*)little, llen) == 0)
		{
			if (llen + i > len)
				return (NULL);
			return ((char*)(big + i));
		}
		i++;
	}
	return (NULL);
}
