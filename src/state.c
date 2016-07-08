/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:22:24 by rpuccine          #+#    #+#             */
/*   Updated: 2015/03/27 18:33:12 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

void	verif_state(t_sys *sys, t_state *state)
{
	t_list	*trav;

	trav = sys->open;
	while (trav)
	{
		if (is_win(state, trav->state->tab))
		{
			if (state->move_cost >= trav->state->move_cost)
				return ;
			else
			{
				extract(&(sys->open), trav);
				insert(&(sys->open), state);
				return ;
			}
		}
		else
			trav = trav->next;
	}
	verif_state2(sys, state, trav);
	insert(&(sys->open), state);
}

int		*set_tab(t_state *state, t_link *link)
{
	int		i;
	int		j;
	int		tmp;
	int		*news;

	if (!(news = (int *)malloc(sizeof(int) * (state->size * state->size))))
		exit(1);
	i = 0;
	while (i < state->size)
	{
		j = 0;
		while (j < state->size)
		{
			news[i * state->size + j] = state->tab[i * state->size + j];
			j++;
		}
		i++;
	}
	tmp = news[link->src];
	news[link->src] = news[link->dst];
	news[link->dst] = tmp;
	return (news);
}

t_state	*set_state(t_sys *sys, t_state *state, t_link *link, int *win_tab)
{
	t_state		*news;

	if (!(news = (t_state *)malloc(sizeof(t_state))))
		exit(1);
	news->size = state->size;
	news->id = sys->id;
	sys->id++;
	news->father = state->id;
	news->tab = set_tab(state, link);
	init_link(news, state);
	news->move_cost = state->move_cost + 1;
	news->heur_cost = sys->heuristic_func(news, win_tab);
	news->total_cost = news->move_cost + news->heur_cost;
	return (news);
}

void	init_link(t_state *state, t_state *last)
{
	int		i;
	int		j;

	if (last == NULL)
		last = state;
	i = get_index(state->tab, 0);
	if (!(state->link = (t_link *)malloc(sizeof(t_link) * 5)))
		exit(1);
	bzero(state->link, sizeof(t_link) * 5);
	j = 0;
	if (i / state->size != 0 && get_index(last->tab, 0) != i - state->size)
	{
		state->link[j].src = i;
		state->link[j].dst = i - state->size;
		state->link[j].end = 1;
		j++;
	}
	init_link2(state, last, &i, &j);
	state->link[j].end = 0;
}
