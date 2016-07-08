/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:01:28 by rpuccine          #+#    #+#             */
/*   Updated: 2014/11/13 16:56:41 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str)
{
	char	*new;

	if (!(new = ft_strnew(ft_strlen(str) + 1)))
		return (NULL);
	return ((char *)ft_memcpy((void *)new, (void *)str, ft_strlen(str)));
}
