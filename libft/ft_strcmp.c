/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:16:11 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/19 14:16:21 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1c;
	unsigned char	*s2c;
	int				i;

	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	i = 0;
	while (s1c[i] == s2c[i] && s1c[i] && s2c[i])
		i++;
	return ((int)s1c[i] - s2c[i]);
}
