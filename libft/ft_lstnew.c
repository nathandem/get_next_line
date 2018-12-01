/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:01:20 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 11:52:24 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** We can't copy `void` elements. That's why we perform the copy with chars,
** not to mean to copy letters but to copy 1 byte at the time.
**
** Passing just the pointer `node->content` to content_copy is not enough
** because when malloc gives a new address to the variable, this value is not
** transfered to `node`. This means that when doing `node->content` after the
** function call, `node->content` points to the original value (not the one
** updated in the function)...
** The separation of the pointer own address and the address it is pointing to
** (its value as a variable) is a little unclear here...
*/

static int	content_copy(t_list *node, void const *src, size_t size)
{
	unsigned int	i;

	if ((node->content = malloc(size)) == NULL)
		return (1);
	i = -1;
	while (++i <= size)
		((char*)node->content)[i] = ((char*)src)[i];
	return (0);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*node;

	if ((node = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		if (content_copy(node, content, content_size))
		{
			free(node);
			return (NULL);
		}
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
