/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 04:34:30 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/11 00:14:00 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_size(int n, int *size, int *isneg)
{
	int		temp;

	temp = n;
	*size = 0;
	*isneg = 0;
	if (n < 0)
	{
		*size += 1;
		temp *= -1;
		*isneg = 1;
	}
	if (n == 0)
		*size += 1;
	while (temp)
	{
		temp /= 10;
		*size += 1;
	}
}

char		*ft_itoa(int n)
{
	char	*new;
	int		size;
	int		isneg;

	set_size(n, &size, &isneg);
	if (!(new = ft_strnew(size + 1)))
		return (NULL);
	if (n == 0)
		new[0] = 48;
	while (n)
	{
		if (isneg)
			new[size - 1] = 48 - (n % 10);
		else
			new[size - 1] = 48 + (n % 10);
		n /= 10;
		size--;
	}
	if (isneg)
		new[0] = '-';
	return (new);
}
