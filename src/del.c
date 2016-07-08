/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 13:51:58 by rpuccine          #+#    #+#             */
/*   Updated: 2015/03/25 16:02:12 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

void	del_state(t_state *state)
{
	free(state->tab);
	free(state->link);
	free(state);
}
