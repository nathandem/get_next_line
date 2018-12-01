/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:34:43 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 10:19:57 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

/*
** The `segment` the subject talks about is a string.
**
** `start` can be 0, mind this case.
*/

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ns;
	unsigned int	i;

	if (!s)
		return (NULL);
	if ((ns = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ns[i] = s[start + i];
		i++;
	}
	ns[i] = 0;
	return (ns);
}
