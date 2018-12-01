/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:39:59 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 09:16:53 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int		i;
	unsigned int		j;
	size_t				dst_len;
	size_t				src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	j = 0;
	if (size < dst_len + 1)
		return (src_len + size);
	if (size > dst_len + 1)
	{
		while (i < size - 1)
			dst[i++] = src[j++];
		dst[i] = 0;
	}
	return (dst_len + src_len);
}
