/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:58:40 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/13 20:58:48 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t len)
{
	if (!len || !s1 || !s2)
		return (0);
	while (*s1 == *s2 && *s1 && *s2 && len > 1)
	{
		s1++;
		s2++;
		len--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
