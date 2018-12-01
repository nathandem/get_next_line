/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:12:03 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 09:57:07 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

/*
** As opposed to `striter` which applies the function on each of the element of
** the string, `strmap` returns a new string in which the elements have been
** transformed by the function.
** Just like the python or the javascript map functions.
*/

char		*ft_strmap(char const *s, char (*f)(char))
{
	char		*ns;
	int			nslen;
	int			i;

	if (!s || !f)
		return (NULL);
	nslen = ft_strlen(s);
	if ((ns = (char*)malloc((nslen + 1) * sizeof(char))) == NULL)
		return (NULL);
	ns[nslen] = 0;
	i = -1;
	while (s[++i])
		ns[i] = f(s[i]);
	return (ns);
}
