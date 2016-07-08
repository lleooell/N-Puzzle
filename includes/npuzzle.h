/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 17:30:06 by rpuccine          #+#    #+#             */
/*   Updated: 2015/04/02 12:16:00 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H
# define NPUZZLE_H

# define FOUND -1
# define NOT_FOUND -2
# define NB_ITER 500
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct		s_link
{
	int				src;
	int				dst;
	int				end;
}					t_link;

typedef struct		s_state
{
	int				id;
	int				father;
	int				move_cost;
	int				heur_cost;
	int				total_cost;
	int				*tab;
	t_link			*link;
	int				size;
}					t_state;

typedef struct		s_tile
{
	int				is_good;
	int				is_free;
	int				col;
	int				line;
	int				goal_col;
	int				goal_line;
}					t_tile;

typedef struct		s_list
{
	struct s_list	*next;
	t_state			*state;
}					t_list;

typedef int			(*t_ptr_heur) (t_state *state, int *win_tab);

typedef struct		s_sys
{
	t_list			*open;
	t_list			*close;
	t_list			*win_path;
	t_ptr_heur		heuristic_func;
	int				file_or_gen;
	int				size;
	int				*win_tab;
	int				size_complexity;
	int				time_complexity;
	int				id;
	int				max_g;
}					t_sys;

/*
** init.c
*/
void				init_sys(t_sys *sys, char *file);
void				init_tab(int *tab, int size);
int					swap_empty(int *tab, int size, int i_zero);
t_state				*init_first_state(t_sys *sys);

/*
** state.c
*/
void				verif_state(t_sys *sys, t_state *state);
int					*set_tab(t_state *state, t_link *link);
t_state				*set_state(t_sys *sys, t_state *state, t_link *link,
								int *win_tab);
void				init_link(t_state *state, t_state *last);

/*
** list.c
*/
void				extract(t_list **ptr_list, t_list *find);
t_list				*create_elem(t_state *state_elem);
t_state				*pop(t_list **ptr_list);
int					push(t_list **ptr_list, t_state *state_elem);
int					append(t_list **ptr_list, t_state *state_elem);
int					insert(t_list **ptr_list, t_state *state_elem);

/*
** a_star.c
*/
int					a_star(t_sys *sys);
int					ida_star(t_sys *sys, t_state *root);
int					recurse_ida(t_sys *sys, t_state *state, int limit);

/*
** win.c
*/
void				you_win(t_sys *sys, t_state *state);
int					is_win(t_state *state, int *win_tab);
int					*build_win_tab(int size);
int					test_solv(t_sys *sys);
void				test_solv_part2(int *solv_tab, int *tab_parity, t_sys *sys);

/*
** tools.c
*/
void				print_list(t_sys *sys, t_list *lst);
void				print_state(int *tab, int size);
int					*dup_tab(int *tab, int size);
void				count_size_complexity(t_sys *sys);

/*
** heuristic.c
*/
int					set_manhattan_cost(t_state *state, int *win_tab);
int					get_tile_manhattan_dist(int index_a, int index_b, int size);
int					get_tile_manhattan_dist_lc(int index_a, int index_b,
												int size, t_tile *tab_lc);
int					add_linear_conflict_cost(t_tile *t, int size);
int					set_mlc_cost(t_state *state, int *win_tab);

/*
** del.c
*/
void				del_state(t_state *state);

/*
** parser.c
*/
t_state				*parse_tab(char *file);
void				print_usage(void);
void				set_opt(t_sys *sys, int ac, char **av);
void				parse_func(int fd, char **str, int size, t_state *state);

/*
** index.c
*/
int					get_index(int *tab, int nb);

/*
** heuristic2.c
*/
int					set_miss_placed_cost(t_state *state, int *win_tab);
int					set_minor_lc_cost(t_state *state, int *win_tab);
void				columns_minor_lc(t_state *state, int *win_tab, int *cost,
										int *testab);
void				lines_minor_lc(t_state *state, int *win_tab, int *cost,
										int *testab);

void				verif_state2(t_sys *sys, t_state *state, t_list	*trav);
void				init_link2(t_state *state, t_state *last, int *i, int *j);
int					insert(t_list **ptr_list, t_state *state_elem);
int					line_conflict(t_tile *t, int size, int i, int j);
int					col_conflict(t_tile *t, int size, int i, int j);

#endif
