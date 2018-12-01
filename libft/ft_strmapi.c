/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:39:48 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 10:02:35 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*ns;
	int			i;

	if (!s || !f)
		return (NULL);
	if ((ns = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		ns[i] = f(i, s[i]);
	return (ns);
}
