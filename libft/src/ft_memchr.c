/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:56:25 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/05 22:01:31 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *str, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (*((unsigned char *)str + i) == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
