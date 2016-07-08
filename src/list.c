/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 15:21:24 by rpuccine          #+#    #+#             */
/*   Updated: 2015/03/30 17:23:09 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

t_list	*create_elem(t_state *state_elem)
{
	t_list	*news;

	if (!(news = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	news->next = NULL;
	news->state = state_elem;
	return (news);
}

void	extract(t_list **ptr_list, t_list *find)
{
	t_list	*trav;

	if (!ptr_list || !*ptr_list)
		return ;
	trav = *ptr_list;
	if (trav == find)
	{
		*ptr_list = find->next;
		return ;
	}
	while (trav->next && trav->next != find)
		trav = trav->next;
	if (!trav->next)
		exit(3);
	trav->next = find->next;
}

t_state	*pop(t_list **ptr_list)
{
	t_list	*trav;
	t_state	*ret;

	if (!ptr_list || !*ptr_list)
		return (NULL);
	trav = *ptr_list;
	if (!trav->next)
	{
		ret = trav->state;
		free(trav);
		*ptr_list = NULL;
		return (ret);
	}
	while (trav->next->next)
		trav = trav->next;
	ret = trav->next->state;
	free(trav->next);
	trav->next = NULL;
	return (ret);
}

int		push(t_list **ptr_list, t_state *state_elem)
{
	t_list	*news;

	if (!ptr_list)
		return (0);
	if (!(news = create_elem(state_elem)))
		return (0);
	if (!(*ptr_list))
	{
		*ptr_list = news;
		return (1);
	}
	news->next = *ptr_list;
	*ptr_list = news;
	return (1);
}

int		append(t_list **ptr_list, t_state *state_elem)
{
	t_list	*news;
	t_list	*trav;

	if (!ptr_list)
		return (0);
	if (!(news = create_elem(state_elem)))
		return (0);
	if (!(*ptr_list))
	{
		*ptr_list = news;
		return (1);
	}
	trav = *ptr_list;
	while (trav->next)
		trav = trav->next;
	trav->next = news;
	return (1);
}
