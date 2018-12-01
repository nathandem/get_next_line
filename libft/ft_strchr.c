/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:01:27 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/19 14:08:48 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return (char*)(s + i);
	if (c == 0)
		return (char*)(s + i);
	return (NULL);
}
