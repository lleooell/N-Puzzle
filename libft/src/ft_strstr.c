/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 22:39:01 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/15 18:30:07 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *chr)
{
	if (!str || !chr)
		return (NULL);
	if (!(*chr))
		return ((char *)str);
	if (!(*str))
		return (NULL);
	if (*str == *chr)
	{
		if (ft_strstr(str + 1, chr + 1) - 1 == str)
			return ((char *)str);
	}
	return (ft_strstr(str + 1, chr));
}
