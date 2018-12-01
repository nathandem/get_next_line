/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:16:43 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/19 14:16:45 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	int			s1_len;
	int			i;

	s1_len = ft_strlen(s1);
	if ((s2 = (char*)malloc(sizeof(char) * (s1_len + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		s2[i] = s1[i];
	s2[i] = 0;
	return (s2);
}
