/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:24:10 by nde-maes          #+#    #+#             */
/*   Updated: 2018/11/27 12:11:42 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adding a node to the head of a linked list is quick and easier than doing
** so at the end of (or the middle). Just: create a new node making its next
** pointer pointing to the previous first node (`*alst`) and change the
** reference to the linked list (`**alst`).
*/

void		ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
