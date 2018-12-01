/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:22:35 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/19 14:31:05 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
** We include terminating 0 because 3rd arg of memcmp is the byte length
** of the strings to compare (this length is assumed to be the same)
*/

char	*ft_strstr(const char *big, const char *little)
{
	size_t	llen;
	int		i;

	if (!*little)
		return ((char*)big);
	llen = ft_strlen(little);
	i = -1;
	while (big[++i])
		if (ft_memcmp((const void*)(big + i), (const void*)little, llen) == 0)
			return ((char*)(big + i));
	return (NULL);
}
