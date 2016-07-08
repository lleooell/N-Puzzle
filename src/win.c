/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 19:00:17 by rpuccine          #+#    #+#             */
/*   Updated: 2015/04/02 14:32:43 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

void	you_win(t_sys *sys, t_state *state)
{
	t_list	*temp;
	int		done;

	done = 0;
	push(&(sys->win_path), state);
	while (!done)
	{
		done = 1;
		temp = sys->close;
		while (temp)
		{
			if (temp->state->id == state->father)
			{
				push(&(sys->win_path), temp->state);
				state = temp->state;
				done = 0;
			}
			temp = temp->next;
		}
	}
}

void	test_solv_part2(int *solv_tab, int *tab_parity, t_sys *sys)
{
	int		tmp;
	int		i;
	int		i_swap;

	i = 0;
	while (i < sys->size * sys->size)
	{
		if (solv_tab[i] != sys->win_tab[i])
		{
			(*tab_parity)++;
			i_swap = get_index(solv_tab, sys->win_tab[i]);
			tmp = solv_tab[i];
			solv_tab[i] = solv_tab[i_swap];
			solv_tab[i_swap] = tmp;
		}
		i++;
	}
}

int		test_solv(t_sys *sys)
{
	t_state	*state;
	int		*solv_tab;
	int		empty_parity;
	int		tab_parity;

	state = sys->open->state;
	solv_tab = dup_tab(state->tab, sys->size);
	empty_parity = get_tile_manhattan_dist(get_index(solv_tab, 0),
		get_index(sys->win_tab, 0), sys->size);
	tab_parity = 0;
	test_solv_part2(solv_tab, &tab_parity, sys);
	if (empty_parity % 2 != tab_parity % 2)
		return (1);
	return (0);
}

int		is_win(t_state *state, int *win_tab)
{
	int		i;
	int		j;
	int		*tab;

	tab = state->tab;
	i = 0;
	while (i < state->size)
	{
		j = 0;
		while (j < state->size)
		{
			if (tab[i * state->size + j] != win_tab[i * state->size + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
