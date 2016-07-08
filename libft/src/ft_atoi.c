/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:34:07 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/13 20:28:41 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	int		isneg;
	int		total;

	isneg = 1;
	total = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			isneg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		total = total * 10 + *str - 48;
		str++;
	}
	return (total * isneg);
}
