/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:17:37 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 09:28:51 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Mind all cases, like `abc/abd` (with n = 2)
**
** if (i < n)
**    return ((int)s1c[i] - s2c[i]);
** else
**    return (0);
** => ensures that if we exit the while loop and `i == n`, we return a `0`
**    Otherwise, the diff of the 2 numbers.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1c;
	unsigned char	*s2c;
	unsigned int	i;

	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	i = 0;
	while (s1c[i] == s2c[i] && s1c[i] && i < n)
		i++;
	if (i < n)
		return ((int)s1c[i] - s2c[i]);
	else
		return (0);
}
