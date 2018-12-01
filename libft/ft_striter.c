/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:24:44 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 09:50:55 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** We pass a pointer address to the function and not the value `f(s[i])`,
** because fist the `f` function takes a pointer on char as argument but also
** because we wouldn't get the result of the transformation done by that
** function where we call it.
** => passing by copy VS passing by address
*/

void		ft_striter(char *s, void (*f)(char *))
{
	int			i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i])
		f(s + i);
}
