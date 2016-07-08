/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:13:08 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/13 16:55:20 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	char	*new;
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	new = (char *)malloc(sizeof(char) * len);
	while (i < len)
	{
		new[i] = *((char *)src + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		*((char *)dst + i) = new[i];
		i++;
	}
	return (dst);
}
