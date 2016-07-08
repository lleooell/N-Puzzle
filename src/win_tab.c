/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 14:48:01 by eruffieu          #+#    #+#             */
/*   Updated: 2015/04/02 12:08:15 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

static void	build_3(int *t)
{
	t[0] = 1;
	t[1] = 2;
	t[2] = 3;
	t[3] = 8;
	t[4] = 0;
	t[5] = 4;
	t[6] = 7;
	t[7] = 6;
	t[8] = 5;
}

static void	build_4(int *t)
{
	t[0] = 1;
	t[1] = 2;
	t[2] = 3;
	t[3] = 4;
	t[4] = 12;
	t[5] = 13;
	t[6] = 14;
	t[7] = 5;
	t[8] = 11;
	t[9] = 0;
	t[10] = 15;
	t[11] = 6;
	t[12] = 10;
	t[13] = 9;
	t[14] = 8;
	t[15] = 7;
}

static void	build_5(int *t)
{
	t[0] = 1;
	t[1] = 2;
	t[2] = 3;
	t[3] = 4;
	t[4] = 5;
	t[5] = 16;
	t[6] = 17;
	t[7] = 18;
	t[8] = 19;
	t[9] = 6;
	t[10] = 15;
	t[11] = 24;
	t[12] = 0;
	t[13] = 20;
	t[14] = 7;
	t[15] = 14;
	t[16] = 23;
	t[17] = 22;
	t[18] = 21;
	t[19] = 8;
	t[20] = 13;
	t[21] = 12;
	t[22] = 11;
	t[23] = 10;
	t[24] = 9;
}

void		print_usage(void)
{
	printf("usage: ./npuzzle [arg] [heuristic]\n");
	printf("\t[arg]:\n\t\t-f + file input \n");
	printf("\t\t-g + size of random generation\n");
	printf("\n\t[heuristic]:\n\t\tmanhattan\n");
	printf("\t\tmisplaced\n\t\tminorLC\n\t\tMLC\n");
	exit(-1);
}

int			*build_win_tab(int size)
{
	int		*t;

	if (!(t = (int *)malloc(sizeof(int) * (25))))
		exit(-1);
	if (size == 3)
		build_3(t);
	else if (size == 4)
		build_4(t);
	else if (size == 5)
		build_5(t);
	else
	{
		printf("size must be between 3 and 5\n");
		exit(0);
	}
	return (t);
}
