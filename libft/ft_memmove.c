/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:54:40 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 08:45:55 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
** Overlap happens when the src is before the dst and some parts of
** the src and the dst are common.
** The solution is to compare the position/address of the 2 pointers,
** if the src >= dst, then copy from left to right, else from right to left.
** (if no overlap when src < dst, coping from right to left doesn't
** change anything)
**
** while (--i > 0)
**     dstc[i] = srcc[i];
** dstc[i] = srcc[i];
** => not i > -1 because it will never happen (`i` is an unsigned int),
**    likewise we add a line for `dstc[i] = srcc[i]` not to miss the last copy.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dstc;
	char			*srcc;
	unsigned int	i;

	dstc = (char*)dst;
	srcc = (char*)src;
	if (src < dst && len)
	{
		i = len;
		while (--i > 0)
			dstc[i] = srcc[i];
		dstc[i] = srcc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dstc[i] = srcc[i];
			i++;
		}
	}
	return (dst);
}
