/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 15:10:17 by eruffieu          #+#    #+#             */
/*   Updated: 2015/04/02 12:08:51 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

void		set_opt(t_sys *sys, int ac, char **av)
{
	if (ac != 4 || (ft_strcmp(av[1], "-f") != 0 && ft_strcmp(av[1], "-g") != 0))
	{
		print_usage();
		exit (-1);
	}
	if (ft_strcmp(av[1], "-g") == 0)
		sys->file_or_gen = atoi(av[2]);
	else
		sys->file_or_gen = -1;
	if (ft_strcmp(av[3], "manhattan") == 0)
		sys->heuristic_func = set_manhattan_cost;
	else if (ft_strcmp(av[3], "misplaced") == 0)
		sys->heuristic_func = set_miss_placed_cost;
	else if (ft_strcmp(av[3], "minorLC") == 0)
		sys->heuristic_func = set_minor_lc_cost;
	else if (ft_strcmp(av[3], "MLC") == 0)
		sys->heuristic_func = set_mlc_cost;
	else
	{
		print_usage();
		exit(-1);
	}
}

static void	check_double(t_state *state)
{
	int		i;
	int		c;

	i = 0;
	while (i < (state->size * state->size))
	{
		c = i + 1;
		while (c < (state->size * state->size))
		{
			if (state->tab[i] == state->tab[c])
			{
				printf("please check file integrity : incorrect data\n");
				exit(-1);
			}
			c++;
		}
		i++;
	}
}

static void	check_file(t_state *state, int place)
{
	int		i;

	i = 0;
	check_double(state);
	if (state->size != sqrt(place))
	{
		printf("please check file integrity : incorrect size parameter\n");
		exit(-1);
	}
	while (i < state->size * state->size)
	{
		if (state->tab[i] == 0)
			return ;
		i++;
	}
	printf("please check file integrity : incorrect data\n");
	exit(-1);
}

void		parse_func(int fd, char **str, int size, t_state *state)
{
	char	**splitted;
	int		place;

	place = 0;
	while (get_next_line(fd, str))
	{
		splitted = ft_strsplit(*str, ' ');
		if (splitted && splitted[0] && size == 0 && splitted[0][0] != '\0' &&
			splitted[0][0] != '#' && (size = atoi(splitted[0])) &&
			(state->tab = (int *)malloc(ft_atoi(splitted[0]) * sizeof(int))))
			state->size = size;
		else if (size != 0)
		{
			size = 1;
			while (splitted[size - 1])
			{
				if (splitted[size - 1][0] == '#')
					break ;
				state->tab[place] = atoi(splitted[size - 1]);
				size++;
				place++;
			}
		}
	}
	check_file(state, place);
}

t_state		*parse_tab(char *file)
{
	int		fd;
	t_state	*state;
	int		size;
	char	*str;

	size = 0;
	if ((fd = open(file, O_RDONLY)) == -1 ||
		!(state = (t_state *)malloc(sizeof(t_state))))
	{
		print_usage();
		exit(-1);
	}
	parse_func(fd, &str, size, state);
	state->id = 0;
	state->father = -1;
	init_link(state, NULL);
	return (state);
}
