/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 14:38:29 by eruffieu          #+#    #+#             */
/*   Updated: 2015/03/27 19:04:25 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

int		set_miss_placed_cost(t_state *state, int *win_tab)
{
	int		cost;
	int		i;
	int		j;

	cost = 0;
	i = 0;
	j = 0;
	while (i < state->size)
	{
		j = 0;
		while (j < state->size)
		{
			if (state->tab[i * state->size + j] != win_tab[i * state->size + j])
				cost++;
			j++;
		}
		i++;
	}
	return (cost);
}

void	lines_minor_lc(t_state *state, int *win_tab, int *cost, int *testab)
{
	int		i;
	int		j;

	i = 0;
	while (i < state->size)
	{
		j = 0;
		while (j < state->size - 1)
		{
			if (state->tab[i * state->size + j] ==
					win_tab[i * state->size + j + 1] &&
						state->tab[i * state->size + j + 1] ==
						win_tab[i * state->size + j])
			{
				*cost += 2;
				testab[i * state->size + j] = -1;
				testab[i * state->size + j + 1] = -1;
			}
			j++;
		}
		i++;
	}
}

void	columns_minor_lc(t_state *state, int *win_tab, int *cost, int *testab)
{
	int		i;
	int		j;

	i = 0;
	while (i < state->size)
	{
		j = 0;
		while (j < state->size - 1)
		{
			if (state->tab[j * state->size + i] ==
					win_tab[j * state->size + i + 1] &&
						state->tab[j * state->size + i + 1] ==
						win_tab[j * state->size + i] &&
							testab[j * state->size + i] != -1 && testab[j *
							state->size + i + 1] != -1)
				*cost += 2;
			j++;
		}
		i++;
	}
}

int		set_minor_lc_cost(t_state *state, int *win_tab)
{
	int		cost;
	int		i;
	int		testab[state->size * state->size];

	i = 0;
	while (i < state->size * state->size)
	{
		testab[i] = 0;
		i++;
	}
	cost = set_manhattan_cost(state, win_tab);
	lines_minor_lc(state, win_tab, &cost, testab);
	columns_minor_lc(state, win_tab, &cost, testab);
	return (cost);
}
