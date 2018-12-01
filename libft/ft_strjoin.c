/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:33:42 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 10:25:12 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

/*
** Good case to show the difference between the buffer len (`ns`) and the
** null-terminating string it contains, and to use functions made before which
** assume a good understand of length vs index.
*/

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*ns;

	if (!s1 || !s2)
		return (NULL);
	if ((ns = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	ft_strcpy(ns, s1);
	ft_strcat(ns, s2);
	return (ns);
}
