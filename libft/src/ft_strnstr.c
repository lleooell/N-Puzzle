/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 23:17:19 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/10 18:41:24 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *chr, size_t len)
{
	if (!(*chr))
		return ((char *)str);
	if (!(*str) || len == 0)
		return (NULL);
	if (*str == *chr)
	{
		if (ft_strnstr(str + 1, chr + 1, len - 1) - 1 == str)
			return ((char *)str);
	}
	return (ft_strnstr(str + 1, chr, len - 1));
}
