/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:01:58 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 09:35:42 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*
** atoi doesn't handle int overflow, i.e. passing 2147483648 reverts to
** -2147483648. (If we add more, it then increases up to 0, then 2147483647
** then reverts to its max min value. The cycle keeps going.
*/

int		ft_atoi(const char *str)
{
	long long	res;
	long long	sign;
	int			i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - 48);
	return (int)(sign * res);
}
