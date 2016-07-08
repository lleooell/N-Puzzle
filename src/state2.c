/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 18:27:49 by eruffieu          #+#    #+#             */
/*   Updated: 2015/03/30 17:29:23 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

void	verif_state2(t_sys *sys, t_state *state, t_list *trav)
{
	trav = sys->close;
	while (trav)
	{
		if (is_win(state, trav->state->tab))
		{
			if (state->move_cost >= trav->state->move_cost)
				return ;
			else
			{
				extract(&(sys->close), trav);
				trav = NULL;
			}
		}
		else
			trav = trav->next;
	}
}

void	init_link2(t_state *state, t_state *last, int *i, int *j)
{
	if (*i / state->size != state->size - 1 &&
		get_index(last->tab, 0) != *i + state->size)
	{
		state->link[*j].src = *i;
		state->link[*j].dst = *i + state->size;
		state->link[*j].end = 1;
		(*j)++;
	}
	if (*i % state->size != 0 && get_index(last->tab, 0) != *i - 1)
	{
		state->link[*j].src = *i;
		state->link[*j].dst = *i - 1;
		state->link[*j].end = 1;
		(*j)++;
	}
	if (*i % state->size != state->size - 1 &&
		get_index(last->tab, 0) != *i + 1)
	{
		state->link[*j].src = *i;
		state->link[*j].dst = *i + 1;
		state->link[*j].end = 1;
		(*j)++;
	}
}

int		insert(t_list **ptr_list, t_state *state_elem)
{
	t_list	*n;
	t_list	*t;
	t_list	*prev;

	if (!(n = create_elem(state_elem)) || !ptr_list)
		return (0);
	if (!(*ptr_list) && (*ptr_list = n))
		return (1);
	t = *ptr_list;
	prev = NULL;
	while (t->next && state_elem->total_cost <= t->state->total_cost
		&& (prev = t))
		t = t->next;
	if (t == *ptr_list)
	{
		if (state_elem->total_cost > t->state->total_cost && (n->next = t))
			*ptr_list = n;
		else
			t->next = n;
	}
	else if (state_elem->total_cost > t->state->total_cost && (prev->next = n))
		n->next = t;
	else
		t->next = n;
	return (1);
}
