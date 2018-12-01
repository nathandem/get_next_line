/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:38:20 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 12:11:15 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** `!lst` ensures that we have a list with at least a node in it.
**
** We first deal with the 1st node of the list, because it's special case,
** it's the only one being pointed by lst2_head.
** We navigate the `lst` linked list, working on each time on the next element
** of the list, so that it's easier to make the previous one points to it.
**
** Note: we don't allocate in the function, as `f` already takes care of
** memory allocation as it returns a new t_list.
**
** Note2: we can't just apply `f` to each node of `lst` and wish to end up with
** "linked" list (with node connected to each other), because malloc allocates
** in random area of the memory, making it impossible for a n node to know
** where the n+1 node is.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst2_head;
	t_list *nextnode;
	t_list *node;

	if (!lst || !f)
		return (NULL);
	if ((lst2_head = f(lst)) == NULL)
		return (NULL);
	node = lst2_head;
	while (lst->next)
	{
		if ((nextnode = f(lst->next)) == NULL)
			return (NULL);
		node->next = nextnode;
		lst = lst->next;
		node = node->next;
	}
	return (lst2_head);
}
