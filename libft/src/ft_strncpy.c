/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:25:08 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/10 20:41:22 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	if (!dst || !src)
		return (NULL);
	if (ft_strlen(src) < len)
	{
		ft_bzero((void *)dst, len);
		return (ft_strcpy(dst, src));
	}
	else
		return ((char *)ft_memcpy((void *)dst, (void *)src, len));
}
