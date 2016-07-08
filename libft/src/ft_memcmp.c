/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:39:17 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/04 20:23:27 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && *((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
		i++;
	if (i == len)
		return (0);
	return ((int)(*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i)));
}
