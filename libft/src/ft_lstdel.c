/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 17:43:44 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/15 21:21:53 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*trav;
	t_list	*temp;

	if (!alst || !*alst)
		return ;
	trav = *alst;
	while (trav)
	{
		del(trav->content, trav->content_size);
		temp = trav->next;
		free(trav);
		trav = temp;
	}
	*alst = NULL;
}
