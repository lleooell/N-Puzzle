/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 23:07:35 by rpuccine          #+#    #+#             */
/*   Updated: 2015/03/30 17:29:53 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

void	count_size_complexity(t_sys *sys)
{
	t_list	*tmp;
	int		size;

	size = 1;
	tmp = sys->open;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	tmp = sys->close;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	if (size > sys->size_complexity)
		sys->size_complexity = size;
	sys->time_complexity++;
}

void	print_list(t_sys *sys, t_list *lst)
{
	t_list	*trav;

	trav = lst;
	while (trav)
	{
		printf("move_cost: %d, heur_cost: %d, total_cost: %d\n",
			trav->state->move_cost,
			trav->state->heur_cost, trav->state->total_cost);
		print_state(trav->state->tab, sys->size);
		if (trav->next == NULL && sys->size >= 4)
			sys->size_complexity = trav->state->move_cost;
		trav = trav->next;
	}
}

void	print_state(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%d ", tab[i * size + j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("--------------------------------------------------\n");
}

int		*dup_tab(int *tab, int size)
{
	int		*new_tab;
	int		i;

	if (!(new_tab = (int *)malloc(sizeof(int) * (size * size))))
		return (NULL);
	i = 0;
	while (i < size * size)
	{
		new_tab[i] = tab[i];
		i++;
	}
	return (new_tab);
}
