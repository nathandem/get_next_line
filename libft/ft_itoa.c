/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:58:48 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 11:38:02 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** `str[len--] = n_abs % 10 + 48;` before the while loop and `get_int_len`
** returning at least 1 are to handle the case of `n = 0`. In this case, we
** have to return a string with a '0' character in it (alongside the required
** terminating 0 at the end).
**
** `nb[len] = 0` sets the last byte of the array to 0 to have a string.
**
** (n1 /= n2) first apply the operation then evaluates, like ++i.
**
** `(unsigned int)-5` is still strangely still worth -5, so casting a negative
** value to an unsigned doesn't make it positive!
**
** Be mindfull of edge inputs, like the dude passing 0 as input.
** or the one passing min int.
*/

static int	get_int_len(int n)
{
	int			len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	n_abs;

	len = get_int_len(n);
	n_abs = (unsigned int)n;
	if (n < 0)
	{
		len++;
		n_abs = -n;
	}
	if ((str = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	str[len--] = 0;
	str[len--] = n_abs % 10 + 48;
	while (n_abs >= 10)
	{
		n_abs /= 10;
		str[len--] = n_abs % 10 + 48;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
