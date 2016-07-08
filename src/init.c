/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 15:15:06 by rpuccine          #+#    #+#             */
/*   Updated: 2015/03/27 18:48:06 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

void	init_sys(t_sys *sys, char *file)
{
	t_state	*first;

	srand(time(NULL));
	sys->open = NULL;
	sys->close = NULL;
	sys->win_path = NULL;
	sys->time_complexity = 0;
	if (sys->file_or_gen > 0)
		first = init_first_state(sys);
	else if (sys->file_or_gen == -1)
		first = parse_tab(file);
	else
	{
		print_usage();
		exit(0);
	}
	sys->size = first->size;
	sys->win_tab = build_win_tab(sys->size);
	first->move_cost = 0;
	first->heur_cost = sys->heuristic_func(first, sys->win_tab);
	first->total_cost = first->heur_cost;
	sys->size_complexity = 0;
	insert(&(sys->open), first);
}

void	init_tab(int *tab, int size)
{
	int		i;
	int		i_zero;

	i = 0;
	i_zero = get_index(tab, 0);
	while (i < NB_ITER)
	{
		i_zero = swap_empty(tab, size, i_zero);
		i++;
	}
}

int		swap_empty(int *tab, int size, int i_zero)
{
	int		i;
	int		god;
	int		move[4];

	i = 0;
	if (i_zero / size != 0 && (move[i] = i_zero - size))
		i++;
	if (i_zero / size != size - 1 && (move[i] = i_zero + size))
		i++;
	if (i_zero % size != 0 && (move[i] = i_zero - 1))
		i++;
	if (i_zero % size != size - 1 && (move[i] = i_zero + 1))
		i++;
	god = move[rand() % i];
	tab[i_zero] = tab[god];
	tab[god] = 0;
	return (god);
}

t_state	*init_first_state(t_sys *sys)
{
	t_state	*first;

	if (!(first = (t_state *)malloc(sizeof(t_state))))
	{
		printf("malloc() at first node failed");
		exit (1);
	}
	first->id = 0;
	first->father = -1;
	first->size = sys->file_or_gen;
	first->tab = build_win_tab(first->size);
	init_tab(first->tab, first->size);
	init_link(first, NULL);
	return (first);
}
