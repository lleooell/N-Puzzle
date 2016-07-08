/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:55:05 by rpuccine          #+#    #+#             */
/*   Updated: 2015/03/30 13:08:24 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

int		get_tile_manhattan_dist(int index_a, int index_b, int size)
{
	int		x_dif;
	int		y_dif;

	x_dif = (index_a % size) - (index_b % size);
	if (x_dif < 0)
		x_dif *= -1;
	y_dif = (index_a / size) - (index_b / size);
	if (y_dif < 0)
		y_dif *= -1;
	return (x_dif + y_dif);
}

int		set_manhattan_cost(t_state *state, int *win_tab)
{
	int		cost;
	int		i;
	int		i_win;

	cost = 0;
	i = 0;
	while (i < state->size * state->size)
	{
		i_win = get_index(win_tab, state->tab[i]);
		cost += get_tile_manhattan_dist(i, i_win, state->size);
		i++;
	}
	return (cost);
}

int		get_tile_manhattan_dist_lc(int index_a, int index_b, int size,
			t_tile *tab_lc)
{
	int		x_dif;
	int		y_dif;
	int		ret;

	tab_lc->line = index_a / size;
	tab_lc->col = index_a % size;
	tab_lc->goal_line = index_b / size;
	tab_lc->goal_col = index_b % size;
	tab_lc->is_free = 1;
	x_dif = (index_a % size) - (index_b % size);
	if (x_dif < 0)
		x_dif *= -1;
	y_dif = (index_a / size) - (index_b / size);
	if (y_dif < 0)
		y_dif *= -1;
	if ((ret = x_dif + y_dif) == 0)
		tab_lc->is_good = 1;
	else
		tab_lc->is_good = 0;
	return (ret);
}

int		add_linear_conflict_cost(t_tile *t, int size)
{
	int		i;
	int		j;
	int		ret;

	ret = 0;
	i = 0;
	while (i < size * size)
	{
		if (!t[i].is_good && t[i].is_free && t[i].line == t[i].goal_line)
		{
			j = t[i].line * size;
			ret += line_conflict(t, size, i, j);
		}
		else if (!t[i].is_good && t[i].is_free && t[i].col == t[i].goal_col)
		{
			j = t[i].col;
			ret += col_conflict(t, size, i, j);
		}
		i++;
	}
	return (ret);
}

int		set_mlc_cost(t_state *state, int *win_tab)
{
	int		cost;
	int		i;
	int		i_win;
	t_tile	*tab_lc;

	cost = 0;
	i = 0;
	if (!(tab_lc = (t_tile *)malloc(sizeof(t_tile) *
			(state->size * state->size))))
		exit(1);
	while (i < state->size * state->size)
	{
		i_win = get_index(win_tab, state->tab[i]);
		cost += get_tile_manhattan_dist_lc(i, i_win, state->size, tab_lc + i);
		i++;
	}
	cost += add_linear_conflict_cost(tab_lc, state->size);
	free(tab_lc);
	return (cost);
}
