/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:43:01 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/10 20:42:11 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t len)
{
	size_t	i;
	char	*pdst;

	if (!dst || !src)
		return (NULL);
	i = 0;
	pdst = (char *)dst;
	while (i < len)
	{
		pdst[i] = *((char *)src + i);
		i++;
	}
	return (dst);
}
