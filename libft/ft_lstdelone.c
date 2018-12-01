/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:06:41 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 11:54:21 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** "Mettre un pointeur à NULL" means to make this pointer points to NULL,
** not to change its value to NULL.
*/

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (!alst || !*alst || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
