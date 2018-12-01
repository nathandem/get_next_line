/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:18:13 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 12:13:00 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The best flow to give to this function is not immediate.
**
** We could as well have done a single while loop (with the condition
** `i < len`) and 2 branches in it based on the test (`src[i]`), if it's true
** do the copy, if not put `0` until reaching the end of `len`.
**
** while (i < len)
**     if (src[i])
**        dst[i] = src[i];
**        i++;
**     else
**        while (i < len)
**            dst[i++] = 0;
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
		dst[i++] = 0;
	return (dst);
}
