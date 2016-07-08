/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 18:57:57 by rpuccine          #+#    #+#             */
/*   Updated: 2015/03/30 13:08:39 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

int		line_conflict(t_tile *t, int size, int i, int j)
{
	int		ret;

	ret = 0;
	while (j < (t[i].line + 1) * size)
	{
		if (i != j && t[j].is_free && t[j].line == t[j].goal_line)
		{
			if (t[i].col > t[j].col && t[i].goal_col < t[j].goal_col)
			{
				ret += 2;
				t[i].is_free = 0;
				t[j].is_free = 0;
				break ;
			}
			else if (t[i].col < t[j].col && t[i].goal_col > t[j].goal_col)
			{
				ret += 2;
				t[i].is_free = 0;
				t[j].is_free = 0;
				break ;
			}
		}
		j++;
	}
	return (ret);
}

int		col_conflict(t_tile *t, int size, int i, int j)
{
	int		ret;

	ret = 0;
	while (j < size * size)
	{
		if (i != j && t[j].is_free && t[j].col == t[j].goal_col)
		{
			if (t[i].line > t[j].line && t[i].goal_line < t[j].goal_line)
			{
				ret += 2;
				t[i].is_free = 0;
				t[j].is_free = 0;
				break ;
			}
			else if (t[i].line < t[j].line && t[i].goal_line > t[j].goal_line)
			{
				ret += 2;
				t[i].is_free = 0;
				t[j].is_free = 0;
				break ;
			}
		}
		j += size;
	}
	return (ret);
}
