/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:22:38 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/13 19:54:27 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*n_list;

	n_list = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		ft_lstappend(&n_list, new);
		lst = lst->next;
	}
	return (n_list);
}
