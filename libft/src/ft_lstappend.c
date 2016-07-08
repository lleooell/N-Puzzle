/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:25:54 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/13 19:52:00 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **lst, t_list *new)
{
	t_list	*trav;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	trav = *lst;
	while (trav->next)
		trav = trav->next;
	trav->next = new;
}
