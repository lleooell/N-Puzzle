/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:54:52 by rpuccine          #+#    #+#             */
/*   Updated: 2015/03/26 16:49:35 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

static void	run_ida_star(t_sys *sys)
{
	if (ida_star(sys, sys->open->state))
	{
		push(&(sys->win_path), sys->open->state);
		print_list(sys, sys->win_path);
	}
	else
		printf("npuzzle can't be resolve\n");
}

static void	run_a_star(t_sys *sys)
{
	if (a_star(sys))
		print_list(sys, sys->win_path);
	else
		printf("npuzzle can't be resolve\n");
}

int			main(int ac, char **av)
{
	t_sys	sys;

	set_opt(&sys, ac, av);
	init_sys(&sys, av[2]);
	if (test_solv(&sys))
	{
		print_list(&sys, sys.open);
		printf("This Puzzle is not solvable\n");
		exit(0);
	}
	if (sys.size > 3)
		run_ida_star(&sys);
	else
		run_a_star(&sys);
	printf("Time complexity: %d\n", sys.time_complexity);
	printf("Size complexity: %d\n", sys.size_complexity);
	return (0);
}
