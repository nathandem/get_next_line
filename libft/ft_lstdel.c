/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:26:51 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/26 13:27:45 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Be careful when doing recursion with pointers, if arguments not passed by
** copy but address, it's quite possible to end with the pointer of all the
** stacks of the recursion to point to the same address.
** Note: `printf("%p", pointer)` helps spot this.
**
** It's now working but don't really know why addresses don't mess up anymore!
*/

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if ((*alst)->next)
		ft_lstdel(&((*alst)->next), del);
	ft_lstdelone(alst, del);
}
