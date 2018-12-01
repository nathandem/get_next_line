/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:12:30 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 08:30:32 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** memset writes to `str` using char not necessarily because it plans to puts
** characters in it, but because char is the type which accesses 1 byte at the
** time.
*/

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned int		i;

	i = 0;
	while (i < len)
	{
		((char*)str)[i] = (char)c;
		i++;
	}
	return (str);
}
