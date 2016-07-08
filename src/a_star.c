/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:53:10 by rpuccine          #+#    #+#             */
/*   Updated: 2015/03/27 18:45:47 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

int		a_star(t_sys *sys)
{
	t_state	*current_state;
	t_state	*new_state;
	t_link	*current_link;

	while (42)
	{
		current_state = pop(&(sys->open));
		if (!current_state)
			return (0);
		count_size_complexity(sys);
		if (is_win(current_state, sys->win_tab))
		{
			you_win(sys, current_state);
			return (1);
		}
		current_link = current_state->link;
		while (current_link->end)
		{
			new_state = set_state(sys, current_state, current_link,
				sys->win_tab);
			verif_state(sys, new_state);
			current_link++;
		}
		push(&(sys->close), current_state);
	}
}

int		ida_star(t_sys *sys, t_state *root)
{
	int		ret;
	int		limit;

	limit = root->heur_cost;
	while (42)
	{
		sys->max_g = 0;
		printf("limite : %d\n", limit);
		sys->id = 1;
		ret = recurse_ida(sys, root, limit);
		if (ret == FOUND)
			return (1);
		limit = ret;
	}
}

int		recurse_ida(t_sys *sys, t_state *state, int limit)
{
	t_link	*current_link;
	t_state	*new_state;
	int		ret;
	int		min;

	sys->time_complexity++;
	if (state->total_cost > limit)
		return (state->total_cost);
	if (is_win(state, sys->win_tab))
		return (FOUND);
	min = -3;
	current_link = state->link;
	while (current_link->end)
	{
		new_state = set_state(sys, state, current_link++, sys->win_tab);
		if ((ret = recurse_ida(sys, new_state, limit)) == FOUND)
		{
			push(&(sys->win_path), new_state);
			return (FOUND);
		}
		else if (min == -3 || ret < min)
			min = ret;
		del_state(new_state);
	}
	return (min);
}
